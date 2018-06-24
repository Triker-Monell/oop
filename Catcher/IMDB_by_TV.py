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
def get_movie_url(url):
    html=get_html(url)
    soup=BeautifulSoup(html,"html.parser")
    name=soup.find('table', class_="findList")
    soup_name=BeautifulSoup(str(name),"html.parser")
    the_url=soup_name.find('a')
    url='https://www.imdb.com'+the_url.get('href')
    return url
def get_all_photos(url):
    t = 1  # 记录张数
    os.chdir(os.path.join(os.getcwd(), 'allphotos'))
    for i in range(1, 10, 1):
        url_min = str(url)[:-17]
        photos_url = url_min + '/mediaindex?page=' + str(i) + '&ref_=tt_pv_mi_sm'

        html = get_html(photos_url)
        soup=BeautifulSoup(html,"html.parser")

        src =soup.find_all('div', class_="media_index_thumb_list" ,id="media_index_thumbnail_grid")

        for myimg in src:

            the_img_src = myimg.find_all('img')

            for the_img_src_it in the_img_src:
                pic_name = str(t) + '.jpg'
                img_src = the_img_src_it.get('src')
                urllib.urlretrieve(img_src, pic_name)
                t += 1

    os.chdir(r'D:\PyCharm 2017.3.4\untitled')
def get_movie_all(html):     #通过soup提取到每个电影的全部信息，以list返回
    soup = BeautifulSoup(html,"html.parser")
    movie_1 = soup.find_all('h1',itemprop="name" ,class_="")
    movie_2 = soup.find_all('span', itemprop="ratingValue")
    movie_3 = soup.find_all('a',title="See more release dates")
    movie_4 = soup.find_all('span', itemprop="director")
    movie_5 = soup.find_all('span', itemprop="actors")
    movie_6 = soup.find_all('div', class_="rec-title")
    movie_7=soup.find_all('div', class_="txt-block")
    movie_8 = soup.find_all('div', class_="article", id="titleImageStrip")
    movie_str=str(movie_1[0])+str(movie_2[0])+str(movie_3[0])+str(movie_8[0])
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
    soup_all = BeautifulSoup(str(movie),"html.parser")
    title = soup_all.find_all('h1')
    soup_title = BeautifulSoup(str(title[0]),"html.parser")
    for line in soup_title.stripped_strings:  # 对获取到的<a>里的内容进行提取
        result.append(line)


    result_str=""

    grade = soup_all.find_all('span', itemprop="ratingValue")
    soup_grade = BeautifulSoup(str(grade[0]),"html.parser")
    for line in soup_grade.stripped_strings:
        result_str=result_str+"rating："+line


    director = soup_all.find_all('span', itemprop="director")
    for line in director:
        soup_director = BeautifulSoup(str(line),"html.parser")
        director_str = soup_director.find_all('span',itemprop="name")
        soup_director = BeautifulSoup(str(director_str[0]))
        for it in soup_director.stripped_strings:
            result_str = result_str  +it+" "

    result_str = result_str+"actor:"

    actor = soup_all.find_all('span', itemprop="actors")
    for _actor in actor:
        soup_actor = BeautifulSoup(str(_actor),"html.parser")
        actor_str = soup_actor.find_all('span',itemprop="name")
        soup_actor = BeautifulSoup(str(actor_str[0]),"html.parser")
        for line in soup_actor.stripped_strings:
            result_str = result_str + line + "  "

    releasedate=soup_all.find_all('a',title="See more release dates")
    soup_releasedate=BeautifulSoup(str(releasedate[0]),"html.parser")
    for line in soup_releasedate.stripped_strings:
        result_str=result_str +" releasedate: " +line


    result_str=result_str+" related TVs: "
    rec_movies=soup_all.find_all('b')
    for it_rec in rec_movies:
        soup_rec_movies=BeautifulSoup(str(it_rec),"html.parser")
        for line in soup_rec_movies.stripped_strings:
            result_str=result_str+line


    result_str=result_str+" "
    boxoffice=soup_all.find_all('div' ,class_="txt-block")
    for it_boxoffice in boxoffice:
        soup_boxoffice=BeautifulSoup(str(it_boxoffice),"html.parser")
        for line in soup_boxoffice.stripped_strings:
            result_str=result_str+line+" "
    result.append(result_str)

    os.chdir(os.path.join(os.getcwd(), 'photos'))
    t = 1  # 记录张数
    src = soup_all.find_all('div', class_="article", id="titleImageStrip")
    for myimg in src:

        the_img_src = myimg.find_all('img')

        for the_img_src_it in the_img_src:
            pic_name = str(t) + '.jpg'
            img_src = the_img_src_it.get('loadlate')
            urllib.urlretrieve(img_src, pic_name)
            t += 1

    os.chdir(r'D:\PyCharm 2017.3.4\untitled')

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
        text="TV: "
        try:
            f = open('IMDB_by_TV.txt', 'r')

            name = f.read()
        finally:
            if f:
                f.close()
                w = open('IMDB_by_TV.txt', 'w')
                w.truncate()
                w.close()
        preurl = 'https://www.imdb.com/find?q=' + name
        url = get_movie_url(preurl)
        html = get_html(url)
        movie_list = get_movie_all(html)
        for movie in movie_list:  # 将每一页中的每个电影信息放入函数中提取
            result = get_movie_one(movie)
            for it in result:
                text=text+ str(it)
            text = text +'\n'+'\t'
            save_file(text, 'IMDB_by_TV.txt')
        get_all_photos(url)

if __name__=='__main__':
   work()