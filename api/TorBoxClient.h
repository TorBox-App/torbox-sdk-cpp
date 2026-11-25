#ifndef TORBOX_API_TORBOX_CLIENT_H_
#define TORBOX_API_TORBOX_CLIENT_H_

#include "HttpClientImpl.h"

#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

namespace torbox {

class Client {
    class BearerClient final : public api::HttpClientImpl {
    public:
        BearerClient(std::string key, const std::string& host, const std::string& port,
                     Transport transport)
            : HttpClientImpl(host, port, transport), key_(std::move(key)) {}

    protected:
        HttpRequest prepareRequest(const std::string& verb, const std::string& target,
                                   const std::string& body,
                                   const std::map<std::string, std::string>& headers) override {
            auto authenticated = headers;
            authenticated.emplace("Authorization", "Bearer " + key_);
            return HttpClientImpl::prepareRequest(verb, target, body, authenticated);
        }

    private:
        std::string key_;
    };

public:
    using Transport = api::HttpClientImpl::Transport;

    explicit Client(std::string apiKey, const std::string& host = "api.torbox.app",
                    const std::string& port = "443", Transport transport = Transport::Https)
        : apiKey_(std::move(apiKey)) {
        if (apiKey_.empty()) throw std::invalid_argument("A TorBox API key is required.");
        transport_ = std::make_shared<BearerClient>(apiKey_, host, port, transport);
    }

    template <typename Api>
    Api api() const {
        return Api(transport_);
    }

    const std::string& apiKey() const noexcept { return apiKey_; }

private:
    std::string apiKey_;
    std::shared_ptr<api::HttpClient> transport_;
};

} // namespace torbox

#endif
