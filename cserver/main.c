// #include <drogon/drogon.h>
//
// void handle_hello(drogon::HttpRequestPtr req, drogon::HttpResponsePtr resp) {
//   resp->setBody("Hello World!");
// }
//
// void handle_ip(drogon::HttpRequestPtr req, drogon::HttpResponsePtr resp) {
//   auto peer_addr = req->getPeerAddr();
//   char ip[64];
//   inet_ntop(AF_INET, &peer_addr.sin_addr, ip, sizeof(ip));
//   
//   std::stringstream ss;
//   ss << "Your IP is: " << ip;
//   
//   resp->setBody(ss.str());
// }
//
// int main() {
//   drogon::App app;
//   app.addListener("0.0.0.0", 8080);
//   
//   app.registerHandler("/hello", &handle_hello);
//   app.registerHandler("/ip", &handle_ip);
//   
//   app.run();
//   return 0;
// }
