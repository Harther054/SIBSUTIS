import requests

from bs4 import BeautifulSoup

def parser():
    response = requests.get("https://coinmarketcap.com")

    soup = BeautifulSoup(response.content, "html.parser")

    for el in soup.select(".h7vnx2-2 czTsgW cmc-table"):
        url_more = el.select('a')
        print(url_more)

parser()
