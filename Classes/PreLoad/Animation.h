//
//  Animation.hpp
//  Test0
//
//  Created by ’≈¥Û∑Ω on 2018/6/7.
//

#ifndef Animation_h
#define Animation_h

#include <stdio.h>

class loadAnimation
{
public:
	void initAnimation();
    void createAnimationByIndexAndName(char* str = "",int start_Index = 0,int end_Index = 0,char* AnimationName = "",float DelayPerUnit = 0.1f);
    
	void createFire();
    void createThor();
    void createDenas();
    void createDarkSlayer();
    
    
};

#endif /* Animation_hpp */

