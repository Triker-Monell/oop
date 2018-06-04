#!/usr/bin/env python
# -*- coding=utf-8 -*-
import sys
import urllib.request
import re
import time
from bs4 import BeautifulSoup
def get_html(url):  #通过url获取网页内容
    result = urllib.request.urlopen(url)
    return result.read()
    # save_file(result.read(), 'thefile.txt')
def get_movie_all(html):     #通过soup提取到每个电影的全部信息，以list返回
    soup = BeautifulSoup(html)
    movie_1 = soup.find_all('ul', class_="content-meta info")
    movie_2=soup.find_all('title')
    movie_3=soup.find_all('div', class_="castSection ")
    movie_4=soup.find_all('div', id="scoreStats" ,class_="hidden-xs")
    movie_5=soup.find_all('span', class_="tMeterScore cfp-item-score")
    movie_str=str(movie_1[0])+str(movie_2[0])+str(movie_3[0])+str(movie_4[0])+str(movie_5[0])
    movie=[movie_str]
    return movie
def get_movie_one(movie):
    result = []  # 用于存储提取出来的电影信息
    soup_all = BeautifulSoup(str(movie))
    title = soup_all.find_all('title')
    soup_title = BeautifulSoup(str(title[0]))
    for line in soup_title.stripped_strings:  # 对获取到的<a>里的内容进行提取
        result.append(line)
    result_str=" | Fresh:"

    fresh=soup_all.find_all('span', class_="tMeterScore cfp-item-score")
    soup_fresh=BeautifulSoup(str(fresh[0]))
    for line in soup_fresh.stripped_strings:
        result_str=result_str+line+" |"

    rating=soup_all.find_all('div', class_="superPageFontColor")
    soup_rating=BeautifulSoup(str(rating[0]))
    for line in soup_rating.stripped_strings:
        result_str=result_str+line
    result_str=result_str+" | Actor: "

    actor=soup_all.find_all('a', class_="unstyled articleLink")
    for it_actor in actor:
        soup_actor = BeautifulSoup(str(it_actor))
        for line in soup_actor.stripped_strings:
            result_str = result_str + line + " "

    info=soup_all.find_all('li' ,class_="meta-row clearfix")
    for it_info in info:
        soup_info=BeautifulSoup(str(it_info))
        for line in soup_info.stripped_strings:
            result_str=result_str+line+" "


    result.append(result_str)



    return result  #返回获取到的结果
def save_file(text, filename):  #保存网页到文件
    f= open(filename,'ab')
    f.write(bytes(text, encoding="utf8"))
    f.close()
def read_file(filename):  #读取文件
    f = open(filename,'r')
    text = f.read()
    f.close()
    return text
def work():

        url = 'https://www.rottentomatoes.com/m/avengers_infinity_war'
        html = get_html(url)
        movie_list = get_movie_all(html)
        for movie in movie_list:  # 将每一页中的每个电影信息放入函数中提取
            result = get_movie_one(movie)
            text = '' + 'movie：' + str(result[0])  + str(result[1]) + '\n' + '\t'
            save_file(text, 'thee.txt')


if __name__=='__main__':
   work()