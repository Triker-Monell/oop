#ifndef _ROTTENTOMATOESSCORE_H
#define _ROTTENTOMATOESSCORE_H

#include "BaseScore.h"
class Critics{
    double AverageRating; //平均得分 满分10 标准1位小数
    int ReviewsCounted; //评价数量
    int FressNumber; //评为 新鲜 的数量
    int RottenNumber; //评为 腐烂 的数量
public:
    Critics():AverageRating(0),ReviewsCounted(0),FressNumber(0),ReviewsCounted(0){};
    Critics(double _AverageRating,int _ReviewsCounted,int _FressNumber,int _RottenNumber):
            AverageRating(_AverageRating),ReviewsCounted(_ReviewsCounted),
            FressNumber(_FressNumber),RottenNumber(_RottenNumber){};
    Critics(std::string data);

    void setAverageRating(double rating);
    void setReviewsCounted(int num);
    void setFressNumber(int num);
    void setRottenNumber(int num);

    double getAverageRating()const;
    int getReviewsCounted()const;
    int getFressNumber()const;
    int getRottenNumber()const;

};

class AudienceScore{
    double LikedIt; //百分比 3.5星以上
    double AverageRating;
    const static MaxRating=5; //5星
    int UserRatings;
public:
    AudienceScore():LikedIt(0),AverageRating(0),UserRatings(0){};
    AudienceScore(double _LikedIt,double _AverageRating,int _UserRatings):
            LikedIt(_LikedIt),AverageRating(_AverageRating),UserRatings(_UserRatings){};
    AudienceScore(std::string data);

    void setLikedIt(double _perc);
    void setAverageRating(double rating);
    void setUserRatings(int num);

    double getLikedIt()const;
    double getAverageRating()const;
    int getUserRatings()const;

};

class RottenTomatoesScore:public BaseScore{
    //basescore代表所有评价新鲜度百分比 0到1
    const static double MaxScore=1; //basescore的最高值

    Critics AllCritics; //所有评价
    Critics TopCritics; //专业人士评价
    std::string CriticsConsensus;

    AudienceScore audience;
public:
    RottenTomatoesScore(): BaseScore("RottenTomatoesScore","complex"){};
    RottenTomatoesScore(
            double _AverageRating_All,int _ReviewsCounted_All,int _FressNumber_All,int _RottenNumber_All,
            double _AverageRating_Top,int _ReviewsCounted_Top,int _FressNumber_Top,int _RottenNumber_Top,
            double _LikedIt,double _AverageRating,int _UserRatings,
            std::string _CriticsConsensus=""
    ):
            BaseScore("RottenTomatoesScore","complex"),
            AllCritics(_AverageRating_All,_ReviewsCounted_All,_FressNumber_All,_RottenNumber_All),
            TopCritics(_AverageRating_Top,_ReviewsCounted_Top,_FressNumber_Top,_RottenNumber_Top),
            audience(_LikedIt,_AverageRating,_UserRatings),
            CriticsConsensus(_CriticsConsensus){};
    RottenTomatoesScore(
            std::string _data_All,std::string _data_Top,
            std::string _data_audience,std::string _CriticsConsensus=""
    ):
            BaseScore("RottenTomatoesScore","complex"),
            AllCritics(_data_All),TopCritics(_data_Top),
            audience(_data_audience),CriticsConsensus(_CriticsConsensus){};
    RottenTomatoesScore(std::string data);
    //标准字符串输入输出
    /*
      新鲜度 All_AverageRating All_ReviewsCounted All_Fresh All_Rotten
      Top_AverageRating Top_ReviewsCounted Top_Fresh Top_Rotten
      CriticsConsensus
      LikedIt AverageRating UserRatings
    */
    /*例如
      88% 7.5/10 73 64 9
      83% 7.5/10 30 25 5
      consensusssssssssssssssssssssssssssss
      77% 4.1/5 1094
    */
    //注:其中所有项目之间均用空格分割


    //AllCritics interface
    void setAverageRating_of_AllCritics(double rating);
    void setReviewsCounted_of_AllCritics(int num);
    void setFressNumber_of_AllCritics(int num);
    void setRottenNumber_of_AllCritics(int num);

    double getAverageRating_of_AllCritics()const;
    int getReviewsCounted_of_AllCritics()const;
    int getFressNumber_of_AllCritics()const;
    int getRottenNumber_of_AllCritics()const;


    //TopCritics interface
    void setAverageRating_of_TopCritics(double rating);
    void setReviewsCounted_of_TopCritics(int num);
    void setFressNumber_of_TopCritics(int num);
    void setRottenNumber_of_TopCritics(int num);

    double getAverageRating_of_TopCritics()const;
    int getReviewsCounted_of_TopCritics()const;
    int getFressNumber_of_TopCritics()const;
    int getRottenNumber_of_TopCritics()const;


    //AudienceScore interface
    void setLikedIt_AudienceScore(double _perc);
    void setAverageRating_AudienceScore(double rating);
    void setUserRatings_AudienceScore(int num);

    double getLikedIt_AudienceScore()const;
    double getAverageRating_AudienceScore()const;
    int getUserRatings_AudienceScore()const;

    //others
    void setCriticsConsensus(std::string consensus);
    std::string getCriticsConsensus()const;

    void setData(std::string newData);
    std::string getData()const;
};

#endif