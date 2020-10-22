#include <iostream>
#include <time.h>


int user_hit(int &, int &, int &);

void input_programNum(int &);
void _rand(int &);

int main(){
    int program_num;
    int user_num;
    int _try = 0;
    int win = 0;
    
    input_programNum(program_num);
    while(win != 1){
        win = user_hit(_try, program_num, user_num);
    }
    
    return 0;
}

void input_programNum(int & program_num){
    _rand(program_num);
}


int user_hit(int& _try, int & program_num, int & user_num){
    int ball, strike;
    int gues;

    _try++;
    ball = 0;
    strike = 0;

    int program_hund = program_num/100;
    int program_ten = (program_num/10)%10;
    int program_one = program_num%10;

    while(1){
        std::cout<<"number: ";
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

    gues = user_num;

    int user_hund = gues/100;
    int user_ten = (gues/10)%10;
    int user_one = gues%10;

    char hit[3];
    hit[0] = user_hund;
    hit[1] = user_ten;
    hit[2] = user_one;

    for(int i = 0; i<3; i++){
        if(hit[i]==program_hund || hit[i] == program_ten || hit[i] == program_one){
            if(i == 0 && hit[i] == program_hund){
                strike++;   
            }
            else if(i == 1 && hit[i] == program_ten){
                strike++;   
            }
            else if(i == 2 && hit[i] == program_one){
                strike++;   
            }
            else{
                ball++;
            }
        }
        
    }
    if(strike == 3){
        std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
        return 1;
    }

    else{
        std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
        return -1;
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
