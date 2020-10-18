#include <iostream>
#include <random>

void program_hitted();
void user_hitted();
void input_programNum();
void input_useNum();

int user_num;
int program_num;

int main(){
    input_programNum();
    std::cout<<"program_num: "<<program_num<<std::endl;

    program_hitted();
    return 0;
}

void input_programNum(){
    int one, two, three;
    std::random_device rd;

    // random_device 를 통해 난수 생성 엔진을 초기화 한다.
    std::mt19937 gen(rd());

    // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
    while(1){
        std::uniform_int_distribution<int> dis(100, 999);
        program_num = dis(gen);

        if( (program_num/100) != (program_num/10)%10 && (program_num/100) != (program_num%10) && (program_num/10)%10 != (program_num%10) )
            break;
    }
}

void input_userNum(){
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

void program_hitted(){
    int gues;
    int ball = 0;
    int strike = 0;

    int pro_hund;
    int pro_ten;
    int pro_one;
    
    int user_hund = user_num/100;
    int user_ten = (user_num/10)%10;
    int user_one = user_num%10;

//    while(1){
        std::random_device rd;
        // random_device 를 통해 난수 생성 엔진을 초기화 한다.
        std::mt19937 gen(rd());
        // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
        while(1){
            std::uniform_int_distribution<int> dis(100, 999);
            program_num = dis(gen);
            gues = program_num;

            pro_hund = gues/100;
            pro_ten = (gues/10)%10;
            pro_one = gues%10;
            
            if( pro_hund != pro_ten && pro_hund != pro_one && pro_ten != pro_one )
                std::cout<<"program think: "<< gues << std::endl;
                break;
        }

        char pro[3];
        pro[0] = pro_hund;
        pro[1] = pro_ten;
        pro[2] = pro_one;

        for(int i = 0; i<3; i++){
            if(pro[i]==user_hund || pro[i] == user_ten || pro[i] == user_one){
                if(i == 0 && pro[i] == user_hund){
                    strike++;   
                }
                else if(i == 1 && pro[i] == user_ten){
                    strike++;   
                }
                else if(i == 2 && pro[i] == user_one){
                    strike++;   
                }
                else{
                    ball++;
                }
            }
            
        }
        std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
        if(strike == 3){
            std::cout<<"End. "<<std::endl;
//            break;
        }
//    }
}

void user_hitted(){
    int gues;
    int user_try = 0;

    int ball;
    int strike;
    while(1){
        user_try ++;
        ball = 0;
        strike = 0;

        int pro_hund = program_num/100;
        int pro_ten = (program_num/10)%10;
        int pro_one = program_num%10;

        std::cout<<"number: ";
        std::cin>>gues;

        int user_hund = gues/100;
        int user_ten = (gues/10)%10;
        int user_one = gues%10;

        char user[3];
        user[0] = user_hund;
        user[1] = user_ten;
        user[2] = user_one;

        for(int i = 0; i<3; i++){
            if(user[i]==pro_hund || user[i] == pro_ten || user[i] == pro_one){
                if(i == 0 && user[i] == pro_hund){
                    strike++;   
                }
                else if(i == 1 && user[i] == pro_ten){
                    strike++;   
                }
                else if(i == 2 && user[i] == pro_one){
                    strike++;   
                }
                else{
                    ball++;
                }
            }
            
        }
        std::cout<<strike<<"s "<<ball<<"b"<<std::endl;
        if(strike == 3){
            std::cout<<"End. You try: "<<user_try<<std::endl;
            break;
        }
    }
    
}