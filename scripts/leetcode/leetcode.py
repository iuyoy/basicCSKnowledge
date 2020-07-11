import requests
from bs4 import BeautifulSoup


LEETCODE_ALLOW_DOMAIN = {
    'us': 'leetcode.com',
    'cn': 'leetcode-cn.com'
}


class LeetCode(object):
    """
    A class to get data from leetcode.com and leetcode-cn.com
    """

    def __init__(self, cookie, type='us'):

        type = type.lower()
        if type in LEETCODE_ALLOW_DOMAIN:
            self.type = type
            self.domain = LEETCODE_ALLOW_DOMAIN[type]
            self.header = {
                'Host': self.domain,
                'Upgrade-Insecure-Requests': '1',
                'Referer': f'https://{self.domain}/',
                'Connection': 'keep-alive',
                'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
                'Accept-Language': 'zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7',
                'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/62.0.3202.94 Safari/537.36',
                'Cache-Control': 'max-age=0',
                'cookie': cookie
            }
            self.session = requests.session()
        else:
            raise(
                f"Unknown leetcode website type:{type}, allowed types are: us and cn.")

    def jointURL(self, path):
        return f"https://{self.domain}/{path}"

    def getAllProblems(self):
        path = "api/problems/all/"
        response = self.session.get(self.jointURL(path), headers=self.header)
        print(response)
        return response.json()
        