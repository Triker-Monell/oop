#!/usr/bin/env python
# -*- coding=utf-8 -*-
import sys
import urllib
import time
from bs4 import BeautifulSoup
reload(sys)
sys.setdefaultencoding('utf-8')
def get_html(url):  #通过url获取网页内容
    result = urllib.urlopen(url)
    return result.read()
    # save_file(result.read(), 'thefile.txt')
def get_movie_all(html):     #通过soup提取到每个电影的全部信息，以list返回
    soup = BeautifulSoup(html,"html.parser")
    movie_list = soup.find_all('div', class_='bd doulist-subject')
    return movie_list
def get_movie_one(movie):
    result = []  # 用于存储提取出来的电影信息
    soup_all = BeautifulSoup(str(movie),"html.parser")
    title = soup_all.find_all('div', class_='title')
    soup_title = BeautifulSoup(str(title[0]),"html.parser")
    for line in soup_title.stripped_strings: 
        result.append(line)

    # num = soup_all.find_all('span', class_='rating_nums')
    num = soup_all.find_all('span')
    result.append(num[1].contents[0])

    soup_num = BeautifulSoup(str(num[0]),"html.parser")
    for line in soup_num.stripped_strings:   
        result = result + line

    info = soup_all.find_all('div', class_='abstract')
    soup_info = BeautifulSoup(str(info[0]),"html.parser")
    result_str = ""
    for line in soup_info.stripped_strings:   
        result_str = result_str + line
    result.append(result_str)
    return result  #返回获取到的结果
def save_file(text, filename):  #保存网页到文件
    f= open(filename,'ab')
    f.write(bytes(text))
    f.close()
def read_file(filename):  #读取文件
    f = open(filename,'r')
    text = f.read()
    f.close()
    return text
def work():
    for i in range(0, 426, 25):
        url = 'https://www.douban.com/doulist/3516235/?start=' + str(i) + '&sort=seq&sub_type='
        html = get_html(url)
        movie_list = get_movie_all(html)
        for movie in movie_list:   
            result = get_movie_one(movie)
            text = '' + '电影名：' + str(result[0]) + ' | 评分：' + str(result[1]) + ' | ' + str(result[2]) + '\n' + '\t'
            save_file(text, '/tmp/infocollection/data/Douban_by_toplist.txt')
        time.sleep(5)  # 每隔5秒抓取一页的信

if __name__=='__main__':
   work()
