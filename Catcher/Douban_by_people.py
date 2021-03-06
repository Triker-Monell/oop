#!/usr/bin/env python
# -*- coding=utf-8 -*-
import sys
import urllib
import os
from bs4 import BeautifulSoup
reload(sys)
sys.setdefaultencoding('utf-8')
def get_html(url):  #通过url获取网页内容
    result = urllib.urlopen(url)
    return result.read()
    # save_file(result.read(), 'thefile.txt')

def get_movie_url(url):
    html=get_html(url)
    soup=BeautifulSoup(html,"html.parser")
    name=soup.find('a', class_="nbg")
    url=name.get('href')
    return url

def get_movie_all(html):     #通过soup提取到每个电影的全部信息，以list返回
    soup = BeautifulSoup(html, "html.parser")
    movie_1 = soup.find_all('title')
    movie_2 = soup.find_all('div', class_='info')
    movie_3 = soup.find_all('span',class_='all hidden')
    movie_4 = soup.find_all('ul', class_="pic-col5")
    movie_str=str(movie_1[0])+str(movie_2[0])+str(movie_3[0])+str(movie_4[0])
    movie=[movie_str]
    return movie
def get_movie_one(movie):
    result = []  # 用于存储提取出来的电影信息
    soup_all = BeautifulSoup(str(movie), "html.parser")
    title = soup_all.find_all('title')
    soup_title = BeautifulSoup(str(title[0]), "html.parser")
    for line in soup_title.stripped_strings:   
        result.append(line)


    result_str=""

    info = soup_all.find_all('div', class_='info')
    for it in info:
        soup_info = BeautifulSoup(str(it), "html.parser")
        for line in soup_info.stripped_strings:
            result_str = result_str + line
    result.append(result_str)

    result_str=""
    intro = soup_all.find_all('span',class_='all hidden')
    soup_intro = BeautifulSoup(str(intro[0]),"html.parser")
    for line in soup_intro.stripped_strings:
        result_str = result_str + line + " "

    os.chdir(os.path.join(os.getcwd(), '/tmp/infocollection/data/photos'))
    t = 1  # 记录张数
    src = soup_all.find_all('ul', class_="pic-col5")
    for myimg in src:

        the_img_src = myimg.find_all('img')

        for the_img_src_it in the_img_src:
            pic_name = str(t) + '.jpg'
            img_src = the_img_src_it.get('src')
            urllib.urlretrieve(img_src, pic_name)
            t += 1

    os.chdir(r'/tmp/infocollection/data/')
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
    try:
        f = open('/tmp/infocollection/data/Douban_by_people.txt', 'r')

        name = f.read()
    finally:
        if f:
            f.close()
            w = open('/tmp/infocollection/data/Douban_by_people.txt', 'w')
            w.truncate()
            w.close()
        preurl = 'https://www.douban.com/search?cat=1005&q=' + str(name)
        url = get_movie_url(preurl)
        html = get_html(url)
        movie_list = get_movie_all(html)
        for movie in movie_list:   
            result = get_movie_one(movie)
            text = '' + '人物名：' + str(result[0])  + str(result[1]) +'\n'+str(result[2])+ '\n' + '\t'
            save_file(text, '/tmp/infocollection/data/Douban_by_people.txt')


if __name__=='__main__':
   work()
