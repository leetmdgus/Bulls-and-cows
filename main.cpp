#include <iostream>
#include <time.h>


void someone_gues(int &, int &, int &);
void pro_hitted(int &, int &, int &);

void input_programNum(int &);
void input_userNum(int &);
void _rand(int &);


int main(){
    int program_num;
    int user_num;
    int _try = 0;

    input_userNum(user_num);
    pro_hitted(_try, program_num,user_num);

    input_programNum(program_num);
    someone_gues(_try, program_num, user_num);

    return 0;
}

void input_programNum(int & program_num){
    _rand(program_num);
}

void input_userNum(int & user_num){
    while(1){
        std::cout<<"your number: ";
        std::cin>>user_num; 

        int user_hund = user_num/100;
        int user_ten = (user_num/10)%10;
        int user_one = user_num % 10;

        if(user_hund == 0){
            std::cout<<"0 can't located at first"<<std::endl;
        }

        else if(user_hund == user_ten || user_hund == user_one || user_ten == user_one){
            std::cout<<"No repetition"<<std::endl;;
        }
        else{
            break;
        }
    }
}

void _rand(int & num){ // 100~999까지 숫자가 겹치지 않는 랜덤 넘버 생성.
    int hund, ten, one;

    while(1){
        srand(time(NULL));
		num = rand()% 900+100;
	    
		hund = num/100;
    	ten = num/10%10;
    	one = num%10;

        if( hund != ten && hund != one && ten != one ){
			std::cout<<"program_num: "<<num<<std::endl; 
			break;
		}
            
    }
}

void someone_gues(int& _try, int & hitted_num, int & hit_num){
    int ball, strike;
    int gues;

    _try++;
    ball = 0;
    strike = 0;

    int hitted_hund = hitted_num/100;
    int hitted_ten = (hitted_num/10)%10;
    int hitted_one = hitted_num%10;

    std::cout<<"number: ";
    std::cin>>gues;
    
    hit_num =  gues;

    int hit_hund = gues/100;
    int hit_ten = (gues/10)%10;
    int hit_one = gues%10;

    char hit[3];
    hit[0] = hit_hund;
    hit[1] = hit_ten;
    hit[2] = hit_one;

    for(int i = 0; i<3; i++){
        if(hit[i]==hitted_hund || hit[i] == hitted_ten || hit[i] == hitted_one){
            if(i == 0 && hit[i] == hitted_hund){
                strike++;   
            }
            else if(i == 1 && hit[i] == hitted_ten){
                strike++;   
            }
            else if(i == 2 && hit[i] == hitted_one){
                strike++;   
            }
            else{
                ball++;
            }
        }
        
    }
    std::cout<<strike<<"s "<<ball<<"b"<<std::endl;

}


void pro_hitted(int & _try, int & program_num, int & user_num){
    int strike = 0, ball = 0;
    _try ++;

    _rand(program_num); //program_num 에 랜덤숫자 넣음
    
    int pro_hund = program_num/100;
    int pro_ten = program_num/10%10;
    int pro_one = program_num%10;

    int user_hund = user_num/100;
    int user_ten = user_num/10%10;
    int user_one = user_num%10;

    char pro[2];

    pro[0] = pro_hund;
    pro[1] = pro_ten;
    pro[2] = pro_one;

    for(int i = 0; i<3; i++){ //// 스트라이크가 하나 더 추가되는 오류 수정해야함.
        if(pro[i]==user_hund || pro[i] == user_ten || pro[i] == user_one){
            if(i == 0 && pro[0] == user_hund){
                strike++;   
            }
            else if(i == 1 && pro[1] == user_ten){
                strike++;   
            }
            else if(i == 2 && pro[2] == user_one){
                strike++;   
            }
            else{
                ball++;
            }
        }
    }
    std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
}
