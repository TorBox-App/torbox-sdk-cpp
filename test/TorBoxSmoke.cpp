#include "api/TorBoxClient.h"
#include "api/TorrentsApi.h"
#include "api/UserApi.h"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    const auto* port = std::getenv("TORBOX_MOCK_PORT");
    if (port == nullptr) {
        std::cerr << "TORBOX_MOCK_PORT is required\n";
        return 1;
    }

    const auto* host = std::getenv("TORBOX_MOCK_HOST");
    torbox::Client client("torbox-sdk-test", host == nullptr ? "127.0.0.1" : host,
                         port, torbox::Client::Transport::Http);
    auto account = client.api<torbox::api::UserApi>().getUserData({}, {}, {});
    if (!account->isSuccess()) throw std::runtime_error("User data request failed.");

    auto torrents = client.api<torbox::api::TorrentsApi>();
    auto upload = torrents.createTorrent(std::string("d8:announce0:e"), boost::none, boost::none,
                                         boost::none, boost::none, boost::none, boost::none, "test.torrent");
    if (!upload->isSuccess()) throw std::runtime_error("Torrent upload failed.");

    auto download = torrents.requestTorrentDownloadLink(client.apiKey(), 1, 0, {}, {}, {}, {});
    if (!download->isSuccess()) throw std::runtime_error("Download link request failed.");
}
