#!/bin/sh
PROJECT_DIR=${PWD}
OUTPUT_DIR=${PROJECT_DIR}/output
CONFIGURATION=Release
PROJECT_NAME="libsignal-protocol-swift iOS"
PRODUCT_NAME=SignalProtocol
SIGNAL_PROTOCOL_OUTPUT_DIR=${OUTPUT_DIR}/SignalModuleMap
UNIVERSAL_OUTPUT_DIR=${OUTPUT_DIR}/${CONFIGURATION}-universal
RELEASE_DIR=${PROJECT_DIR}/build

get_dependencies()
(
    git submodule update --init --recursive
)

build_c_library()
(
    PLATFORM=$1

    mkdir -p "${SIGNAL_PROTOCOL_OUTPUT_DIR}/${PLATFORM}"
    cd "${SIGNAL_PROTOCOL_OUTPUT_DIR}/${PLATFORM}"
    cmake "${PROJECT_DIR}/libsignal-protocol-c" -G Xcode -DCMAKE_TOOLCHAIN_FILE="${PROJECT_DIR}/ios-cmake/iOS.toolchain.cmake" -DPLATFORM=${PLATFORM}

    make clean
    mkdir -p "${OUTPUT_DIR}/OS64"
    cmake --build .  --config Release --target install

    cp -R "/usr/local/lib/libsignal-protocol-c.a" "${OUTPUT_DIR}/SignalModuleMap/${PLATFORM}/"
    cd ${PROJECT_DIR}
)

build_c_libraries()
(
    build_c_library "OS64"
    build_c_library "SIMULATOR64"
)

build_signal_module()
(
    xcodebuild -create-xcframework \
        -library "${SIGNAL_PROTOCOL_OUTPUT_DIR}/OS64/libsignal-protocol-c.a" -headers "/usr/local/include/signal/" \
        -library "${SIGNAL_PROTOCOL_OUTPUT_DIR}/SIMULATOR64/libsignal-protocol-c.a" -headers "/usr/local/include/signal/" \
        -output "${SIGNAL_PROTOCOL_OUTPUT_DIR}/SignalModule.xcframework"
    
    cp -R "${SIGNAL_PROTOCOL_OUTPUT_DIR}/SignalModule.xcframework" "${RELEASE_DIR}"
)

build_swift_framework()
(
    PLATFORM=$1
    
    xcodebuild -target "${PROJECT_NAME}" ONLY_ACTIVE_ARCH=NO -configuration ${CONFIGURATION} CONFIGURATION_BUILD_DIR="${OUTPUT_DIR}/${PLATFORM}" build -sdk ${PLATFORM}
)

build_swift_frameworks()
(
    build_swift_framework "iphoneos"
    build_swift_framework "iphonesimulator"
)

build_swift_xcframework()
(
    xcodebuild -create-xcframework \
        -output "${UNIVERSAL_OUTPUT_DIR}/${PRODUCT_NAME}.xcframework" \
        -framework "${OUTPUT_DIR}/iphonesimulator/${PRODUCT_NAME}.framework" \
        -framework "${OUTPUT_DIR}/iphoneos/${PRODUCT_NAME}.framework"
        
    rm -rf "${UNIVERSAL_OUTPUT_DIR}/${PRODUCT_NAME}.xcframework/ios-arm64_x86_64-simulator/${PRODUCT_NAME}.framework"
    cp -R ${OUTPUT_DIR}/iphonesimulator/${PRODUCT_NAME}.framework ${UNIVERSAL_OUTPUT_DIR}/${PRODUCT_NAME}.xcframework/ios-arm64_x86_64-simulator/

    rm -rf "${UNIVERSAL_OUTPUT_DIR}/${PRODUCT_NAME}.xcframework/ios-arm64/${PRODUCT_NAME}.framework"
    cp -R ${OUTPUT_DIR}/iphoneos/${PRODUCT_NAME}.framework ${UNIVERSAL_OUTPUT_DIR}/${PRODUCT_NAME}.xcframework/ios-arm64/
    
    cp -R "${UNIVERSAL_OUTPUT_DIR}/${PRODUCT_NAME}.xcframework" "${RELEASE_DIR}"
)

(
    get_dependencies
    mkdir -p "${UNIVERSAL_OUTPUT_DIR}"
    build_c_libraries
    build_signal_module
    build_swift_frameworks
    build_swift_xcframework
    rm -rf ${OUTPUT_DIR}
    open ${RELEASE_DIR}
)
