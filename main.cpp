#include <iostream>
#include <time.h>

int user_hit(int &, int &, int &);
int pro_hit(int &, int &, int &);


void input_programNum(int &);
void input_userNum(int &);
void _rand(int &);

int mean_value[3] = {-1,-1,-1};
int trash_value[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int i = 2;


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



void _rand(int & num){ // 100~999까지 숫자가 겹치지 않는 랜덤 넘버 생성. // 랜덤함수 중복숫자 나오는 에러 수정 해야함
    int hund, ten, one;
    srand(time(NULL));
    
    while(1){
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

int pro_hit(int &_try, int &user_num, int & program_num){
    int ball = 0, strike = 0;
   
    int user_hund = user_num/100;
    int user_ten = (user_num/10)%10;
    int user_one = user_num%10;
    
    int new_num;

    std::cout<<(int)trash_value[0]<<std::endl;
    if(trash_value[0] == -1){
        _rand(program_num);

        int pro_hund = program_num/100;
        int pro_ten = (program_num/10)%10;
        int pro_one = program_num%10;

        char hit[3];
        hit[0] = pro_hund;
        hit[1] = pro_ten;
        hit[2] = pro_one;

        for(int i = 0; i<3; i++){
            if(hit[i]==user_hund || hit[i] == user_ten || hit[i] == user_one){
                if(i == 0 && hit[i] == user_hund){
                    strike++;   
                }
                else if(i == 1 && hit[i] == user_ten){
                    strike++;   
                }
                else if(i == 2 && hit[i] == user_one){
                    strike++;   
                }
                else{
                    ball++;
                }
            }
        }

        if(strike == 0 && ball == 0){
            std::cout<<strike<<"s "<<ball<<"b    ";
            std::cout<<program_num<<std::endl;

            trash_value[0] = pro_hund;
            trash_value[1] = pro_ten;
            trash_value[2] = pro_one;
            return -1;

        }
        else if(strike == 3){
            std::cout<<strike<<"s "<<ball<<"b     ";
            std::cout<<program_num<<std::endl;
            return 1;
        }
        else{
            std::cout<<strike<<"s "<<ball<<"b    ";
            std::cout<<program_num<<std::endl;
            return -1;
        }
    }

    else if(mean_value[0] == -1){
        while(1){
            srand(time(NULL));
            new_num = rand()%9+1;
            if(new_num != trash_value[0]||new_num != trash_value[1]||new_num != trash_value[2]||new_num != trash_value[3]||new_num != trash_value[4]||new_num != trash_value[5]||new_num != trash_value[6]||new_num != trash_value[7]){
                std::cout<<"program_num: "<<new_num<<(int)trash_value[1]<<(int)trash_value[2]<<std::endl;
                break;
            }
        }
        if(new_num != user_one && new_num != user_ten && new_num !=user_hund){
            i++;
            trash_value[i] = new_num;
        }
        else{
            if(new_num == user_hund){
                strike ++;
            }
            ball ++;
        }
        if(strike == 1){
            std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
            mean_value[0] = new_num;
            return -1;
        }
        else{
            std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
            return -1;
        }
    }
    // else if (mean_value[1]==-1){
    //     while(1){
    //         srand(time(NULL));
    //         new_num = rand()%9+1;
    //         if(new_num != trash_value[0]||new_num != trash_value[1]||new_num != trash_value[2]||new_num != trash_value[3]||new_num != trash_value[4]||new_num != trash_value[5]||new_num != trash_value[6]||new_num != trash_value[7]){
    //             std::cout<<(int)mean_value[0]<<new_num<<(int)trash_value[2]<<std::endl;
    //             break;
    //         }
    //     }
    //     if(new_num != user_one && new_num != user_ten && new_num !=user_hund){
    //         i++;
    //         trash_value[i] = new_num;
    //     }
    //     else{
    //         if(new_num == user_hund){
    //             strike ++;
    //         }
    //         mean_value[2] = new_num;
    //         ball ++;
    //     }
    //     if(strike == 1){
    //         std::cout<<"2s 0b"<<std::endl;
    //         mean_value[1] = new_num;
    //         return -1;
    //     }
    //     else{
    //         std::cout<<"1s "<<ball<<"b"<<std::endl;
    //         return -1;
    //     }


    // }
    // else if (mean_value[2]==-1){
    //     while(1){
    //         srand(time(NULL));
    //         new_num = rand()%9+1;
    //         if(new_num != trash_value[0]||new_num != trash_value[1]||new_num != trash_value[2]||new_num != trash_value[3]||new_num != trash_value[4]||new_num != trash_value[5]||new_num != trash_value[6]||new_num != trash_value[7]){
    //             std::cout<<(int)mean_value[0]<<(int)mean_value[1]<<new_num<<std::endl;
    //             break;
    //         }
    //     }
    //     if(new_num != user_one){
    //         i++;
    //         trash_value[i] = new_num;
    //     }
    //     else{
    //         strike ++;
    //     }
    //     if(strike == 1){
    //         std::cout<<"3s 0b"<<std::endl;
    //         mean_value[1] = new_num;
    //         return 1;
    //     }
    //     else{
    //         std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
    //         return -1;
    //     }


    // }
    // else{
    //      return 1;
    // }   
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

