#include <c++/4.8.3/string>
#include "Verificateur_Bloc.h"
#include <iostream>
#include "Bloc.h"
using namespace std;

int difficulte = 4;

bool Verificateur_Bloc::VerificateurBloc(std::string pubkey, Bloc bloc) {
    return VerificateurHash(bloc) && VerificateurDifficulte(bloc) && VerificateurTransaction(pubkey, bloc);
}

bool Verificateur_Bloc::VerificateurTransaction(std::string pubkey, Bloc bloc) {
    std::vector<TXI> entree = bloc.tx1.TXIs;
    std::vector<UTXO> sorties = bloc.tx1.UTXOs;
    bool testentree;
    //le prof a dit on a une seule transac mais je fais quand même une boucle
    for(int i = 0; i<entree.size(); i++){
        testentree = testentree && verify(pubkey, bloc.hash, entree.at(i).signature);
    }
    if(!testentree) {
        cout << "transaction incorrecte";
        return false;
    }
    else
        return true;
}

bool Verificateur_Bloc::VerificateurDifficulte(Bloc bloc) {
    bool difficulteok;
    for(int i=0; i<4; i++){
        if(bloc.hash[i]=!'0')
            difficulteok = difficulteok && false;
    }
    if(!difficulteok){
        cout << "difficulte incorrecte";
        return false;
    }
    else return true;
}

bool Verificateur_Bloc::VerificateurHash(Bloc bloc) {
    bool hashok = verifHash(bloc, bloc.hash);
    if(!hashok) {
        cout << "hash incorrect";
        return false;
    }
    return true;
}

//juste pour tester
//juste pour tester

bool Verificateur_Bloc::verifHash(Bloc totest, char *hashtotest) {
    return true;
}

bool Verificateur_Bloc::verify(std::string pubkey, char *hash, unsigned char *signature) {
    return true;
}
