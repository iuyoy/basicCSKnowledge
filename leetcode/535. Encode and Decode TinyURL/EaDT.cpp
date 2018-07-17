/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/
class Solution {
private:
    string chars = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
    unordered_map<string, string> url2code;
    unordered_map<string, string> code2url;
    random_device rd;
    string generateShortUrl(){
        string shortUrl;
        for(int i=0; i<6; ++i)
            shortUrl.push_back(chars[rd()%chars.size()]);
        return shortUrl;
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        if(url2code.find(longUrl) != url2code.end())
            code = url2code[longUrl];
        else{
            code = generateShortUrl();
            while(code2url.find(code) != code2url.end())
                code = generateShortUrl();
            code2url[code] = longUrl;
            url2code[longUrl] = code;
        }
        return "http://tinyurl.com/" + code;
        // return code;

    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl = shortUrl.substr(shortUrl.size()-6, 6);
        if(code2url.find(shortUrl) == code2url.end())
            return "http://tinyurl.com/404";//404 Page in fact
        return code2url[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
