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
    movie_1 = soup.find_all('h1',itemprop="name" ,class_="")
    movie_2 = soup.find_all('span', itemprop="ratingValue")
    movie_3 = soup.find_all('a',title="See more release dates")
    movie_4 = soup.find_all('span', itemprop="director")
    movie_5 = soup.find_all('span', itemprop="actors")
    movie_6 = soup.find_all('div', class_="rec-title")
    movie_7=soup.find_all('div', class_="txt-block")
    movie_str=str(movie_1[0])+str(movie_2[0])+str(movie_3[0])
    for it in movie_4:
        movie_str=movie_str+str(it)
    for it in movie_5:
        movie_str=movie_str+str(it)
    for it in movie_6:
        movie_str=movie_str+str(it)
    for it in movie_7:
        movie_str = movie_str + str(it)

    movie=[movie_str]
    return movie
def get_movie_one(movie):
    result = []  # 用于存储提取出来的电影信息
    soup_all = BeautifulSoup(str(movie))
    title = soup_all.find_all('h1')
    soup_title = BeautifulSoup(str(title[0]))
    for line in soup_title.stripped_strings:  # 对获取到的<a>里的内容进行提取
        result.append(line)

    result_str=""

    grade = soup_all.find_all('span', itemprop="ratingValue")
    soup_grade = BeautifulSoup(str(grade[0]))
    for line in soup_grade.stripped_strings:
        result_str=result_str+"rating："+line

    result_str=result_str+" director:"
    director = soup_all.find_all('span', itemprop="director")
    for line in director:
        soup_director = BeautifulSoup(str(line))
        director_str = soup_director.find_all('span',itemprop="name")
        soup_director = BeautifulSoup(str(director_str[0]))
        for it in soup_director.stripped_strings:
            result_str = result_str  +it+" "

    result_str = result_str+"actor:"

    actor = soup_all.find_all('span', itemprop="actors")
    for _actor in actor:
        soup_actor = BeautifulSoup(str(_actor))
        actor_str = soup_actor.find_all('span',itemprop="name")
        soup_actor = BeautifulSoup(str(actor_str[0]))
        for line in soup_actor.stripped_strings:
            result_str = result_str + line + "  "

    releasedate=soup_all.find_all('a',title="See more release dates")
    soup_releasedate=BeautifulSoup(str(releasedate[0]))
    for line in soup_releasedate.stripped_strings:
        result_str=result_str +" releasedate:" +line


    result_str=result_str+" related movies:"
    rec_movies=soup_all.find_all('b')
    for it_rec in rec_movies:
        soup_rec_movies=BeautifulSoup(str(it_rec))
        for line in soup_rec_movies.stripped_strings:
            result_str=result_str+line


    result_str=result_str+" "
    boxoffice=soup_all.find_all('div' ,class_="txt-block")
    for it_boxoffice in boxoffice:
        soup_boxoffice=BeautifulSoup(str(it_boxoffice))
        for line in soup_boxoffice.stripped_strings:
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
        text="movie: "
        url = 'https://www.imdb.com/title/tt2861424/'
        html = get_html(url)
        movie_list = get_movie_all(html)
        for movie in movie_list:  # 将每一页中的每个电影信息放入函数中提取
            result = get_movie_one(movie)
            for it in result:
                text=text+ str(it)
            text = text +'\n'+'\t'
            save_file(text, 'thee.txt')


if __name__=='__main__':
   work()