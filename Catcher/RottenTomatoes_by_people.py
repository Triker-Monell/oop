#!/usr/bin/env python
# -*- coding=utf-8 -*-
import sys
import os
import urllib
from bs4 import BeautifulSoup
reload(sys)
sys.setdefaultencoding('utf-8')
def get_html(url):  #通过url获取网页内容
    result = urllib.urlopen(url)
    return result.read()
    # save_file(result.read(), 'thefile.txt')
def get_movie_all(html):     #通过soup提取到每个电影的全部信息，以list返回
    soup = BeautifulSoup(html,"html.parser")
    movie_1 = soup.find_all('h1', class_="bottom_divider" ,style="margin-top:0")
    movie_2=soup.find_all('div', class_="col-sm-17 celeb_bio")
    movie_3=soup.find_all('tbody')
    movie_4=soup.find_all('link', rel="image_src")
    movie_str=str(movie_1[0])+str(movie_2[0])+str(movie_3[0])+str(movie_4[0])
    movie=[movie_str]
    return movie
def get_movie_one(movie,peoplename):
    result = []  # 用于存储提取出来的电影信息
    soup_all = BeautifulSoup(str(movie),"html.parser")
    name = soup_all.find_all('h1', class_="bottom_divider" ,style="margin-top:0")
    soup_name = BeautifulSoup(str(name[0]),"html.parser")
    for line in soup_name.stripped_strings:  # 对获取到的<a>里的内容进行提取
        result.append(line)
    result_str=" | info: "


    info=soup_all.find_all('div', class_="celeb_bio_row")
    for it_info in info:
        soup_info=BeautifulSoup(str(it_info),"html.parser")
        for line in soup_info.stripped_strings:
            result_str=result_str+line+" "
    result_str=result_str+" movies: "
    movies=soup_all.find_all('tbody')
    for it_movies in movies:
        soup_movies = BeautifulSoup(str(it_movies),"html.parser")
        for line in soup_movies.stripped_strings:
            result_str = result_str + line + "  "
     os.chdir(os.path.join(os.getcwd(), '钟闰鑫写'))
    t = 0
    post = soup_all.find('link')
    if (post != None):
        pic_name = peoplename.replace('_', '') + str(0) + '.jpg'
        link = post.get('href')

        urllib.urlretrieve(link, pic_name)

    os.chdir(r'钟闰鑫写')

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
        f = open('/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/RottenTomatoes_by_people.txt', 'r')

        people_name= f.read()
    finally:
        if f:
            f.close()
            w = open('/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/RottenTomatoes_by_people.txt', 'w')
            w.truncate()
            w.close()
        url = 'https://www.rottentomatoes.com/celebrity/'+people_name
        html = get_html(url)
        movie_list = get_movie_all(html)
        for movie in movie_list:  # 将每一页中的每个电影信息放入函数中提取
            result = get_movie_one(movie,peoplename)
            text = '' + 'name：' + str(result[0])  + str(result[1]) + '\n' + '\t'
            save_file(text, '/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/RottenTomatoes_by_people.txt')


if __name__=='__main__':
   work()
