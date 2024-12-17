add_executable(${PROJECT})

target_sources(${PROJECT} PRIVATE
    main.cpp
    ${SEDUTIL_PATH}/Common/DtaAnnotatedDump.cpp
    ${SEDUTIL_PATH}/Common/DtaCommand.cpp
    ${SEDUTIL_PATH}/Common/DtaDev.cpp
    ${SEDUTIL_PATH}/Common/DtaDevEnterprise.cpp
    ${SEDUTIL_PATH}/Common/DtaDevGeneric.cpp
    ${SEDUTIL_PATH}/Common/DtaDevOpal1.cpp
    ${SEDUTIL_PATH}/Common/DtaDevOpal2.cpp
    ${SEDUTIL_PATH}/Common/DtaDevOpal.cpp
    ${SEDUTIL_PATH}/Common/DtaDiskType.cpp
    ${SEDUTIL_PATH}/Common/DtaHashPwd.cpp
    ${SEDUTIL_PATH}/Common/DtaHexDump.cpp
    ${SEDUTIL_PATH}/Common/DtaResponse.cpp
    ${SEDUTIL_PATH}/Common/DtaSession.cpp
    ${SEDUTIL_PATH}/Common/pbkdf2/blockwise.c
    ${SEDUTIL_PATH}/Common/pbkdf2/chash.c
    ${SEDUTIL_PATH}/Common/pbkdf2/hmac.c
    ${SEDUTIL_PATH}/Common/pbkdf2/pbkdf2.c
    ${SEDUTIL_PATH}/Common/pbkdf2/sha1.c
    ${SEDUTIL_PATH}/linux/DtaDevOS.cpp
    ${SEDUTIL_PATH}/linux/DtaDevLinuxNvme.cpp
    ${SEDUTIL_PATH}/linux/DtaDevLinuxSata.cpp
)

target_include_directories(${PROJECT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(${PROJECT} PRIVATE 
    ${CMAKE_CURRENT_LIST_DIR}/include
    ${SEDUTIL_PATH}/Common
    ${SEDUTIL_PATH}/Common/pbkdf2
    ${SEDUTIL_PATH}/linux
)