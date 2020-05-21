//
// Created by Ravoavy Christian on 21/05/2020.
//
#include "Bloc.h"
#ifndef PROGPARCOMPOSANT_VERIFICATEUR_BLOC_H
#define PROGPARCOMPOSANT_VERIFICATEUR_BLOC_H


class Verificateur_Bloc {
public:
    static bool verify(std::string pubkey, char hash[HASH_SIZE], unsigned char signature[64]);
    static bool verifHash(Bloc totest, char hashtotest[HASH_SIZE]);
    static bool VerificateurHash(Bloc bloc);
    static bool VerificateurDifficulte(Bloc bloc);
    static bool VerificateurTransaction(std::string pubkey, Bloc bloc);
    static bool VerificateurBloc(std::string pubkey, Bloc bloc);
};


#endif //PROGPARCOMPOSANT_VERIFICATEUR_BLOC_H
