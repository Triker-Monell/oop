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
    movie_1 = soup.find_all('h1' ,class_="header")
    movie_2 = soup.find_all('div', id="name-born-info" ,class_="txt-block")
    movie_3 = soup.find_all('div' ,class_="infobar", id="name-job-categories")
    movie_4=soup.find_all('div',class_="article")
    movie_str=str(movie_1[0])+str(movie_2[0])+str(movie_3[0])
    for all in movie_4:
        movie_str=movie_str+str(all)
    movie=[movie_str]
    return movie
def get_movie_one(movie):
    result = []  # 用于存储提取出来的电影信息
    soup_all = BeautifulSoup(str(movie))
    title = soup_all.find_all('h1' ,class_="header")
    soup_title = BeautifulSoup(str(title[0]))
    for line in soup_title.stripped_strings:  # 对获取到的<a>里的内容进行提取
        result.append(line)

    result_str=""

    info = soup_all.find_all('div', id="name-born-info" ,class_="txt-block")
    soup_info = BeautifulSoup(str(info[0]))
    for line in soup_info.stripped_strings:  # 对获取到的<a>里的内容进行提取
        result_str=result_str+" "+line

    result_str=result_str+" job: "
    job= soup_all.find_all('div' ,class_="infobar", id="name-job-categories")
    for it in job:
        soup_job = BeautifulSoup(str(it))
        for line in soup_job.stripped_strings:  # 对获取到的<span>里的内容进行提取
            result_str = result_str + line
    result_str = result_str + " movies:"
    movies = soup_all.find_all('span', class_="knownfor-ellipsis")
    for it in movies:
        soup_movies = BeautifulSoup(str(it))
        for line in soup_movies.stripped_strings:  # 对获取到的<span>里的内容进行提取
            result_str = result_str + line

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

        url = 'https://www.imdb.com/name/nm0000375/'
        html = get_html(url)
        movie_list = get_movie_all(html)
        for movie in movie_list:  # 将每一页中的每个电影信息放入函数中提取
            result = get_movie_one(movie)
            text = str(result[0])  + str(result[1]) + '\n' + '\t'
            save_file(text, 'thee.txt')


if __name__=='__main__':
   work()