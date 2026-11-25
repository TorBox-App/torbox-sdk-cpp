cmake_minimum_required(VERSION 3.14)
project(torbox-sdk VERSION 9.3.2026112508 LANGUAGES CXX)

include(GNUInstallDirs)

if (POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
endif ()

set(BOOST_BOOST_TARGET_PREDEFINED FALSE)
set(BOOST_JSON_TARGET_PREDEFINED FALSE)
if (TARGET Boost::boost)
    set(BOOST_BOOST_TARGET_PREDEFINED TRUE)
endif ()
if (TARGET Boost::json)
    set(BOOST_JSON_TARGET_PREDEFINED TRUE)
endif ()

find_package(Boost 1.75 REQUIRED COMPONENTS json)

# Imported targets created in this subdirectory are otherwise invisible to
# sibling consumers when this project is included with add_subdirectory().
if (NOT BOOST_BOOST_TARGET_PREDEFINED)
    set_property(TARGET Boost::boost PROPERTY IMPORTED_GLOBAL TRUE)
endif ()
if (NOT BOOST_JSON_TARGET_PREDEFINED)
    set_property(TARGET Boost::json PROPERTY IMPORTED_GLOBAL TRUE)
endif ()
set(THREADS_TARGET_PREDEFINED FALSE)
if (TARGET Threads::Threads)
    set(THREADS_TARGET_PREDEFINED TRUE)
endif ()
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

if (NOT THREADS_TARGET_PREDEFINED)
    set_property(TARGET Threads::Threads PROPERTY IMPORTED_GLOBAL TRUE)
endif ()

set(OPENSSL_SSL_TARGET_PREDEFINED FALSE)
set(OPENSSL_CRYPTO_TARGET_PREDEFINED FALSE)
if (TARGET OpenSSL::SSL)
    set(OPENSSL_SSL_TARGET_PREDEFINED TRUE)
endif ()
if (TARGET OpenSSL::Crypto)
    set(OPENSSL_CRYPTO_TARGET_PREDEFINED TRUE)
endif ()

find_package(OpenSSL 1.1.0 REQUIRED COMPONENTS SSL Crypto)

# Imported targets created in this subdirectory are otherwise invisible to
# sibling consumers when this project is included with add_subdirectory().
if (NOT OPENSSL_SSL_TARGET_PREDEFINED)
    set_property(TARGET OpenSSL::SSL PROPERTY IMPORTED_GLOBAL TRUE)
endif ()
if (NOT OPENSSL_CRYPTO_TARGET_PREDEFINED)
    set_property(TARGET OpenSSL::Crypto PROPERTY IMPORTED_GLOBAL TRUE)
endif ()


if (MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else ()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall")
endif ()


add_library(${PROJECT_NAME} SHARED)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_EXTENSIONS OFF)

target_sources(${PROJECT_NAME} PRIVATE
# models
    model/AddReferralToAccountResponse.cpp
    model/AddReferralToAccountResponse.h
    model/AddRss.cpp
    model/AddRss.h
    model/AddRssFeedResponse.cpp
    model/AddRssFeedResponse.h
    model/AddTo1Fichier.cpp
    model/AddTo1Fichier.h
    model/AddToDropbox.cpp
    model/AddToDropbox.h
    model/AddToGofile.cpp
    model/AddToGofile.h
    model/AddToGoogleDrive.cpp
    model/AddToGoogleDrive.h
    model/AddToOnedrive.cpp
    model/AddToOnedrive.h
    model/AddToPixeldrain.cpp
    model/AddToPixeldrain.h
    model/ApiError.cpp
    model/ApiError.h
    model/AsyncCreateTorrentResponse.cpp
    model/AsyncCreateTorrentResponse.h
    model/AsyncCreateUsenetDownloadResponse.cpp
    model/AsyncCreateUsenetDownloadResponse.h
    model/AsyncCreateWebDownloadResponse.cpp
    model/AsyncCreateWebDownloadResponse.h
    model/BaseSettingsModel.cpp
    model/BaseSettingsModel.h
    model/CancelSpecificJobResponse.cpp
    model/CancelSpecificJobResponse.h
    model/ChatFile.cpp
    model/ChatFile.h
    model/ChatRequest.cpp
    model/ChatRequest.h
    model/CheckCached.cpp
    model/CheckCached.h
    model/ClearAllNotificationsResponse.cpp
    model/ClearAllNotificationsResponse.h
    model/ClearSingleNotificationResponse.cpp
    model/ClearSingleNotificationResponse.h
    model/ControlQueuedDownload.cpp
    model/ControlQueuedDownload.h
    model/ControlQueuedDownloadsResponse.cpp
    model/ControlQueuedDownloadsResponse.h
    model/ControlRss.cpp
    model/ControlRss.h
    model/ControlRssFeedResponse.cpp
    model/ControlRssFeedResponse.h
    model/ControlTag.cpp
    model/ControlTag.h
    model/ControlTagResponse.cpp
    model/ControlTagResponse.h
    model/ControlTorrent.cpp
    model/ControlTorrent.h
    model/ControlTorrentResponse.cpp
    model/ControlTorrentResponse.h
    model/ControlUsenetDownload.cpp
    model/ControlUsenetDownload.h
    model/ControlUsenetDownloadResponse.cpp
    model/ControlUsenetDownloadResponse.h
    model/ControlWebDownload.cpp
    model/ControlWebDownload.h
    model/ControlWebDownloadResponse.cpp
    model/ControlWebDownloadResponse.h
    model/CreateStreamResponse.cpp
    model/CreateStreamResponse.h
    model/CreateStreamResponse_data.cpp
    model/CreateStreamResponse_data.h
    model/CreateStreamResponse_data_intro_information.cpp
    model/CreateStreamResponse_data_intro_information.h
    model/CreateStreamResponse_data_metadata.cpp
    model/CreateStreamResponse_data_metadata.h
    model/CreateStreamResponse_data_metadata_audios_inner.cpp
    model/CreateStreamResponse_data_metadata_audios_inner.h
    model/CreateStreamResponse_data_metadata_video.cpp
    model/CreateStreamResponse_data_metadata_video.h
    model/CreateStreamResponse_data_search_metadata.cpp
    model/CreateStreamResponse_data_search_metadata.h
    model/CreateStreamResponse_data_search_metadata_titles_full_inner.cpp
    model/CreateStreamResponse_data_search_metadata_titles_full_inner.h
    model/CreateTorrentResponse.cpp
    model/CreateTorrentResponse.h
    model/CreateTorrentResponse_data.cpp
    model/CreateTorrentResponse_data.h
    model/CreateUsenetDownloadResponse.cpp
    model/CreateUsenetDownloadResponse.h
    model/CreateUsenetDownloadResponse_data.cpp
    model/CreateUsenetDownloadResponse_data.h
    model/CreateWebDownloadResponse.cpp
    model/CreateWebDownloadResponse.h
    model/CreateWebDownloadResponse_data.cpp
    model/CreateWebDownloadResponse_data.h
    model/DeleteAccountResponse.cpp
    model/DeleteAccountResponse.h
    model/DeleteAccountSchema.cpp
    model/DeleteAccountSchema.h
    model/DeleteAssistantConversationResponse.cpp
    model/DeleteAssistantConversationResponse.h
    model/DeleteAssistantConversationsResponse.cpp
    model/DeleteAssistantConversationsResponse.h
    model/DeleteAssistantConversationsResponse_data.cpp
    model/DeleteAssistantConversationsResponse_data.h
    model/DeviceTokenSchema.cpp
    model/DeviceTokenSchema.h
    model/EditRssFeedResponse.cpp
    model/EditRssFeedResponse.h
    model/EditTag.cpp
    model/EditTag.h
    model/EditTagResponse.cpp
    model/EditTagResponse.h
    model/EditTagResponse_data.cpp
    model/EditTagResponse_data.h
    model/EditTorrent.cpp
    model/EditTorrent.h
    model/EditTorrentItemResponse.cpp
    model/EditTorrentItemResponse.h
    model/EditUsenetDownload.cpp
    model/EditUsenetDownload.h
    model/EditUsenetItemResponse.cpp
    model/EditUsenetItemResponse.h
    model/EditUserSettingsResponse.cpp
    model/EditUserSettingsResponse.h
    model/EditWebDownload.cpp
    model/EditWebDownload.h
    model/EditWebDownloadItemResponse.cpp
    model/EditWebDownloadItemResponse.h
    model/ExportTorrentDataResponse.cpp
    model/ExportTorrentDataResponse.h
    model/Get30DayStatsResponse.cpp
    model/Get30DayStatsResponse.h
    model/Get30DayStatsResponse_data_inner.cpp
    model/Get30DayStatsResponse_data_inner.h
    model/GetAllJobsByHashResponse.cpp
    model/GetAllJobsByHashResponse.h
    model/GetAllJobsResponse.cpp
    model/GetAllJobsResponse.h
    model/GetAssistantUsageResponse.cpp
    model/GetAssistantUsageResponse.h
    model/GetAssistantUsageResponse_data.cpp
    model/GetAssistantUsageResponse_data.h
    model/GetChangelogsJsonResponse.cpp
    model/GetChangelogsJsonResponse.h
    model/GetChangelogsJsonResponse_data_inner.cpp
    model/GetChangelogsJsonResponse_data_inner.h
    model/GetConfirmationCodeResponse.cpp
    model/GetConfirmationCodeResponse.h
    model/GetHosterListResponse.cpp
    model/GetHosterListResponse.h
    model/GetHosterListResponse_data_inner.cpp
    model/GetHosterListResponse_data_inner.h
    model/GetNewsServerAccountResponse.cpp
    model/GetNewsServerAccountResponse.h
    model/GetNewsServerAccountResponse_data.cpp
    model/GetNewsServerAccountResponse_data.h
    model/GetNewsServerConnectionInformationResponse.cpp
    model/GetNewsServerConnectionInformationResponse.h
    model/GetNewsServerConnectionInformationResponse_data.cpp
    model/GetNewsServerConnectionInformationResponse_data.h
    model/GetNotificationFeedResponse.cpp
    model/GetNotificationFeedResponse.h
    model/GetNotificationFeedResponse_data_inner.cpp
    model/GetNotificationFeedResponse_data_inner.h
    model/GetOauthIntegrationsResponse.cpp
    model/GetOauthIntegrationsResponse.h
    model/GetOauthIntegrationsResponse_data.cpp
    model/GetOauthIntegrationsResponse_data.h
    model/GetQueuedDownloadsResponse.cpp
    model/GetQueuedDownloadsResponse.h
    model/GetQueuedDownloadsResponse_data_inner.cpp
    model/GetQueuedDownloadsResponse_data_inner.h
    model/GetReferralDataResponse.cpp
    model/GetReferralDataResponse.h
    model/GetReferralDataResponse_data.cpp
    model/GetReferralDataResponse_data.h
    model/GetRssFeedItemsResponse.cpp
    model/GetRssFeedItemsResponse.h
    model/GetRssFeedItemsResponse_data_inner.cpp
    model/GetRssFeedItemsResponse_data_inner.h
    model/GetSpecificJobResponse.cpp
    model/GetSpecificJobResponse.h
    model/GetSpecificJobResponse_data.cpp
    model/GetSpecificJobResponse_data.h
    model/GetSpeedtestFilesResponse.cpp
    model/GetSpeedtestFilesResponse.h
    model/GetSpeedtestFilesResponse_data_inner.cpp
    model/GetSpeedtestFilesResponse_data_inner.h
    model/GetSpeedtestFilesResponse_data_inner_coordinates.cpp
    model/GetSpeedtestFilesResponse_data_inner_coordinates.h
    model/GetStatsResponse.cpp
    model/GetStatsResponse.h
    model/GetStatsResponse_data.cpp
    model/GetStatsResponse_data.h
    model/GetStreamDataResponse.cpp
    model/GetStreamDataResponse.h
    model/GetStreamDataResponse_data.cpp
    model/GetStreamDataResponse_data.h
    model/GetSubscriptionsResponse.cpp
    model/GetSubscriptionsResponse.h
    model/GetSubscriptionsResponse_data_inner.cpp
    model/GetSubscriptionsResponse_data_inner.h
    model/GetTagsResponse.cpp
    model/GetTagsResponse.h
    model/GetTagsResponse_data.cpp
    model/GetTagsResponse_data.h
    model/GetTagsResponse_data_string.cpp
    model/GetTagsResponse_data_string.h
    model/GetTokenFromDeviceCodeProcessResponse.cpp
    model/GetTokenFromDeviceCodeProcessResponse.h
    model/GetTokenFromDeviceCodeProcessResponse_data.cpp
    model/GetTokenFromDeviceCodeProcessResponse_data.h
    model/GetTorrentCachedAvailabilityBatchResponse.cpp
    model/GetTorrentCachedAvailabilityBatchResponse.h
    model/GetTorrentCachedAvailabilityResponse.cpp
    model/GetTorrentCachedAvailabilityResponse.h
    model/GetTorrentInfoFromFileResponse.cpp
    model/GetTorrentInfoFromFileResponse.h
    model/GetTorrentInfoFromFileResponse_data.cpp
    model/GetTorrentInfoFromFileResponse_data.h
    model/GetTorrentInfoResponse.cpp
    model/GetTorrentInfoResponse.h
    model/GetTorrentInfoResponse_data.cpp
    model/GetTorrentInfoResponse_data.h
    model/GetTorrentInfoResponse_data_files_inner.cpp
    model/GetTorrentInfoResponse_data_files_inner.h
    model/GetTorrentListResponse.cpp
    model/GetTorrentListResponse.h
    model/GetTorrentListResponse_data_inner.cpp
    model/GetTorrentListResponse_data_inner.h
    model/GetTorrentListResponse_data_inner_files_inner.cpp
    model/GetTorrentListResponse_data_inner_files_inner.h
    model/GetTransactionsResponse.cpp
    model/GetTransactionsResponse.h
    model/GetTransactionsResponse_data_inner.cpp
    model/GetTransactionsResponse_data_inner.h
    model/GetUpStatusResponse.cpp
    model/GetUpStatusResponse.h
    model/GetUsenetCachedAvailabilityBatchResponse.cpp
    model/GetUsenetCachedAvailabilityBatchResponse.h
    model/GetUsenetCachedAvailabilityResponse.cpp
    model/GetUsenetCachedAvailabilityResponse.h
    model/GetUsenetListResponse.cpp
    model/GetUsenetListResponse.h
    model/GetUsenetListResponse_data_inner.cpp
    model/GetUsenetListResponse_data_inner.h
    model/GetUserDataResponse.cpp
    model/GetUserDataResponse.h
    model/GetUserDataResponse_data.cpp
    model/GetUserDataResponse_data.h
    model/GetUserDataResponse_data_settings.cpp
    model/GetUserDataResponse_data_settings.h
    model/GetUserDataResponse_data_settings_dashboard_filter.cpp
    model/GetUserDataResponse_data_settings_dashboard_filter.h
    model/GetUserRssFeedsResponse.cpp
    model/GetUserRssFeedsResponse.h
    model/GetUserRssFeedsResponse_data_inner.cpp
    model/GetUserRssFeedsResponse_data_inner.h
    model/GetUserStatsResponse.cpp
    model/GetUserStatsResponse.h
    model/GetUserStatsResponse_data.cpp
    model/GetUserStatsResponse_data.h
    model/GetUserStatsResponse_data_bandwidth_inner.cpp
    model/GetUserStatsResponse_data_bandwidth_inner.h
    model/GetUserStatsResponse_data_general.cpp
    model/GetUserStatsResponse_data_general.h
    model/GetVendorAccountResponse.cpp
    model/GetVendorAccountResponse.h
    model/GetVendorAccountResponse_data.cpp
    model/GetVendorAccountResponse_data.h
    model/GetVendorUserResponse.cpp
    model/GetVendorUserResponse.h
    model/GetVendorUserResponse_data.cpp
    model/GetVendorUserResponse_data.h
    model/GetVendorUsersResponse.cpp
    model/GetVendorUsersResponse.h
    model/GetVendorUsersResponse_data_inner.cpp
    model/GetVendorUsersResponse_data_inner.h
    model/GetWebDownloadCachedAvailabilityBatchResponse.cpp
    model/GetWebDownloadCachedAvailabilityBatchResponse.h
    model/GetWebDownloadCachedAvailabilityResponse.cpp
    model/GetWebDownloadCachedAvailabilityResponse.h
    model/GetWebDownloadListResponse.cpp
    model/GetWebDownloadListResponse.h
    model/GetWebDownloadListResponse_data_inner.cpp
    model/GetWebDownloadListResponse_data_inner.h
    model/HTTPValidationError.cpp
    model/HTTPValidationError.h
    model/LinkDiscordRolesResponse.cpp
    model/LinkDiscordRolesResponse.h
    model/LinkedRolesData.cpp
    model/LinkedRolesData.h
    model/ListAssistantConversationsResponse.cpp
    model/ListAssistantConversationsResponse.h
    model/ListAssistantConversationsResponse_data_inner.cpp
    model/ListAssistantConversationsResponse_data_inner.h
    model/ListAssistantConversationsResponse_data_inner_support.cpp
    model/ListAssistantConversationsResponse_data_inner_support.h
    model/MagnetToTorrent.cpp
    model/MagnetToTorrent.h
    model/ModifyRss.cpp
    model/ModifyRss.h
    model/OAuthRegisterRequest.cpp
    model/OAuthRegisterRequest.h
    model/OauthSuccessResponse.cpp
    model/OauthSuccessResponse.h
    model/ReadAssistantConversationResponse.cpp
    model/ReadAssistantConversationResponse.h
    model/ReadAssistantConversationResponse_data.cpp
    model/ReadAssistantConversationResponse_data.h
    model/ReadAssistantConversationResponse_data_messages_inner.cpp
    model/ReadAssistantConversationResponse_data_messages_inner.h
    model/RefreshApiTokenResponse.cpp
    model/RefreshApiTokenResponse.h
    model/RefreshTokenSchema.cpp
    model/RefreshTokenSchema.h
    model/RefreshVendorUsersResponse.cpp
    model/RefreshVendorUsersResponse.h
    model/RegisterOauthLinkResponse.cpp
    model/RegisterOauthLinkResponse.h
    model/RegisterVendorResponse.cpp
    model/RegisterVendorResponse.h
    model/RegisterVendorResponse_data.cpp
    model/RegisterVendorResponse_data.h
    model/RegisterVendorUserResponse.cpp
    model/RegisterVendorUserResponse.h
    model/RegisterVendorUserResponse_data.cpp
    model/RegisterVendorUserResponse_data.h
    model/RemoveVendorUserResponse.cpp
    model/RemoveVendorUserResponse.h
    model/RequestDownloadBatch.cpp
    model/RequestDownloadBatch.h
    model/RequestTorrentDownloadLinkResponse.cpp
    model/RequestTorrentDownloadLinkResponse.h
    model/RequestTorrentDownloadLinksGetResponse.cpp
    model/RequestTorrentDownloadLinksGetResponse.h
    model/RequestTorrentDownloadLinksGetResponse_data_inner.cpp
    model/RequestTorrentDownloadLinksGetResponse_data_inner.h
    model/RequestTorrentDownloadLinksPostResponse.cpp
    model/RequestTorrentDownloadLinksPostResponse.h
    model/RequestUsenetDownloadLinkResponse.cpp
    model/RequestUsenetDownloadLinkResponse.h
    model/RequestUsenetDownloadLinksGetResponse.cpp
    model/RequestUsenetDownloadLinksGetResponse.h
    model/RequestUsenetDownloadLinksPostResponse.cpp
    model/RequestUsenetDownloadLinksPostResponse.h
    model/RequestWebDownloadLinkResponse.cpp
    model/RequestWebDownloadLinkResponse.h
    model/RequestWebDownloadLinksGetResponse.cpp
    model/RequestWebDownloadLinksGetResponse.h
    model/RequestWebDownloadLinksPostResponse.cpp
    model/RequestWebDownloadLinksPostResponse.h
    model/ResetNewsServerAccountPasswordResponse.cpp
    model/ResetNewsServerAccountPasswordResponse.h
    model/SendTestNotificationResponse.cpp
    model/SendTestNotificationResponse.h
    model/StartDeviceCodeAuthorizationProcessResponse.cpp
    model/StartDeviceCodeAuthorizationProcessResponse.h
    model/StartDeviceCodeAuthorizationProcessResponse_data.cpp
    model/StartDeviceCodeAuthorizationProcessResponse_data.h
    model/UnregisterOauthLinkResponse.cpp
    model/UnregisterOauthLinkResponse.h
    model/UpdateVendorAccountResponse.cpp
    model/UpdateVendorAccountResponse.h
    model/UploadTo1fichierResponse.cpp
    model/UploadTo1fichierResponse.h
    model/UploadToGofileResponse.cpp
    model/UploadToGofileResponse.h
    model/UploadToGoogleDriveResponse.cpp
    model/UploadToGoogleDriveResponse.h
    model/UploadToGoogleDriveResponse_data.cpp
    model/UploadToGoogleDriveResponse_data.h
    model/UploadToOnedriveResponse.cpp
    model/UploadToOnedriveResponse.h
    model/UploadToPixeldrainResponse.cpp
    model/UploadToPixeldrainResponse.h
    model/ValidationError.cpp
    model/ValidationError.h
# apis
    api/AssistantApi.cpp
    api/AssistantApi.h
    api/GeneralApi.cpp
    api/GeneralApi.h
    api/IntegrationsApi.cpp
    api/IntegrationsApi.h
    api/NotificationsApi.cpp
    api/NotificationsApi.h
    api/QueuedApi.cpp
    api/QueuedApi.h
    api/RssApi.cpp
    api/RssApi.h
    api/StreamApi.cpp
    api/StreamApi.h
    api/TagsApi.cpp
    api/TagsApi.h
    api/TorrentsApi.cpp
    api/TorrentsApi.h
    api/UsenetApi.cpp
    api/UsenetApi.h
    api/UserApi.cpp
    api/UserApi.h
    api/VendorsApi.cpp
    api/VendorsApi.h
    api/WebDownloadsApi.cpp
    api/WebDownloadsApi.h
# other
    api/HttpClient.h
    api/HttpClientImpl.cpp
    api/HttpClientImpl.h
    model/AnyType.h
    model/ValidationTypes.h
    model/NullableField.h
    model/Oas31DeepEqual.h
    model/Oas31ExactNumber.cpp
    model/Oas31ExactNumber.h
    model/Oas31SchemaIr.h
    model/Oas31ExactJson.h
    model/Oas31Validator.h
    model/schema_ir.generated.cpp
    model/schema_ir.generated.chunk0.cpp
    model/schema_ir.generated.chunk1.cpp
    model/schema_ir.generated.chunk2.cpp
    model/schema_ir.generated.chunk3.cpp
    model/schema_ir.generated.chunk4.cpp
    model/schema_ir.generated.chunk5.cpp
    model/Oas31SchemaRegistry.h
)


target_link_libraries(${PROJECT_NAME}
    PUBLIC Boost::boost Boost::json OpenSSL::SSL Threads::Threads)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/api>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/model>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/api>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/model>)

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")

install(DIRECTORY api model
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}"
    FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

# ──────────────────────────────────────────────────────────────────────
# Wire-level multipart encoding test executable.
# Build and run:
#   cmake -DMULTIPART_ENCODING_SELF_TEST=ON -B build
#   cmake --build build --parallel
#   ctest --test-dir build --output-on-failure
# ──────────────────────────────────────────────────────────────────────
option(MULTIPART_ENCODING_SELF_TEST "Enable multipart encoding wire-level self-test" OFF)
if (MULTIPART_ENCODING_SELF_TEST)
    enable_testing()
    add_executable(${PROJECT_NAME}_multipart_wire_test
        test/MultipartWireTest.cpp)

    set_property(TARGET ${PROJECT_NAME}_multipart_wire_test
        PROPERTY CXX_STANDARD 17)
    target_link_libraries(${PROJECT_NAME}_multipart_wire_test
        PRIVATE Boost::boost)

    add_test(NAME multipart-encoding-wire-test
        COMMAND ${PROJECT_NAME}_multipart_wire_test)
endif ()

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_property(TARGET ${PROJECT_NAME} PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)

option(TORBOX_BUILD_TESTS "Build the TorBox API smoke test" OFF)
if (TORBOX_BUILD_TESTS)
    enable_testing()
    add_executable(torbox-smoke test/TorBoxSmoke.cpp)
    target_link_libraries(torbox-smoke PRIVATE ${PROJECT_NAME})
    add_test(NAME torbox-smoke COMMAND torbox-smoke)
endif ()
