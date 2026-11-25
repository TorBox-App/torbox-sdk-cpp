# TorBox C++ SDK

C++17 client for the [TorBox API](https://api-docs.torbox.app) using Boost.Beast and OpenSSL.
Install the Boost.JSON and OpenSSL development packages before configuring CMake.

```cmake
include(FetchContent)
FetchContent_Declare(torbox
  GIT_REPOSITORY https://github.com/TorBox-App/torbox-sdk-cpp.git
  GIT_TAG v9.3.2026112508
)
FetchContent_MakeAvailable(torbox)
target_link_libraries(your_app PRIVATE torbox-sdk)
```

```cpp
#include <cstdlib>
#include <iostream>
#include "api/TorBoxClient.h"
#include "api/UserApi.h"

int main() {
    const auto* key = std::getenv("TORBOX_API_KEY");
    if (key == nullptr) return 1;

    torbox::Client client(key);
    auto response = client.api<torbox::api::UserApi>().getUserData({}, {}, {});
    if (!response->isSuccess()) return 1;
    std::cout << boost::json::serialize(response->toJsonValue()) << '\n';
}
```

The client uses HTTPS by default. For download link endpoints, pass `client.apiKey()` as the `token` argument.
For multipart uploads, pass the file bytes and filename separately. See the
[API reference](https://api-docs.torbox.app/reference) for examples.
