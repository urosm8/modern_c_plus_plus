#include<iostream>
#include<algorithm>
#include<iterator>
#include<numeric>



void printVector(const std::vector<int>& vec){
    std::for_each(vec.begin(),vec.end(),[](const int& i){std::cout<<i<<" ";});
    std::cout<<std::endl;
}


int main(int argc, char const *argv[])
{
    
    std::vector<int> prviVektor(20);
    std::cout<<"Definicija prviVektor"<<std::endl;
    printVector(prviVektor);

    int init = 0;
    std::generate(prviVektor.begin(),prviVektor.end(),[&init]{return init+=5;});
    std::cout<<"Dodeljivanje vrednosti prviVektor"<<std::endl;
    printVector(prviVektor);

    std::transform(prviVektor.begin(),prviVektor.end(),prviVektor.begin(),[](const int& i){return i*i;});
    std::cout<<"Kvadriranje prviVektor"<<std::endl;
    printVector(prviVektor);

    std::vector<int> drugiVektor;

    std::copy_if(prviVektor.begin(),prviVektor.end(),std::back_inserter(drugiVektor),[](const int& i){return i%7;});
    std::cout<<"prviVektor"<<std::endl;
    printVector(prviVektor);
    std::cout<<"drugiVektor"<<std::endl;
    printVector(drugiVektor);

    double reciprocnaSuma= std::accumulate(drugiVektor.begin(),drugiVektor.end(),0.0,[](double x, double y){return x + 1./y;});
    std::cout<<"Reciprocna suma= "<<reciprocnaSuma<<std::endl;
    std::cout<<"drugiVektor pre brisanja"<<std::endl;
    printVector(drugiVektor);

    drugiVektor.erase(
        std::remove_if(
            drugiVektor.begin(),drugiVektor.end(),
            [](const int& i){return i%9==0;}
        ),
        drugiVektor.end()
    );
    std::cout<<"drugiVektor nakon brisanja"<<std::endl;
    printVector(drugiVektor);

    auto it = std::find_if(drugiVektor.begin(),drugiVektor.end(),[](const int& i){return !(i%13);});
    std::cout<<"Indeks elementa deljivog sa 13"<<std::endl;
    std::cout<< ((it!=drugiVektor.end())?it-drugiVektor.begin():-1)<<std::endl;


    return 0;
}
