//
// Created by 方浩铭 on 2022/10/20.
//

#ifndef INC_6_2SAVINGJAMESBOND_EASYVERSION_CROCODILE_H
#define INC_6_2SAVINGJAMESBOND_EASYVERSION_CROCODILE_H

#endif //INC_6_2SAVINGJAMESBOND_EASYVERSION_CROCODILE_H


class Crocodile{
private:
    int x; //x坐标
    int y; //y坐标
public:
    //构造函数
    Crocodile(){
        this->x = 0;
        this->y = 0;
    }
    Crocodile(int x,int y){
        this->x = x;
        this->y = y;
    }
    int getX(){
        return this->x;
    }
    int getY(){
        return this->y;
    }
};