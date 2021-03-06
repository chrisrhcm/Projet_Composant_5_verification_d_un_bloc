#pragma once
#ifndef _BLOC_H

#include <vector>
#include <c++/4.8.3/string>

//
// bloc.h  version 1.1
//
// projet blockchain M2IF 2018-2019-2020
//

#define KEY_SIZE 64 // taille en byte des cle (publique, privee) a valider avec les groupes specifiant et developpant la signature
#define HASH_SIZE 64  // taille du hash, 256 bits chaine hexadecimale
#define SIGNATURE_SIZE 64

class TXI // input d'une transaction
{
public:
    unsigned int nBloc; // block number of the source Utxo
    unsigned int nTx;   // hash of the previous transaction
    unsigned int nUtxo; // index of output ( la référence d'une transaction précédente)
    unsigned char signature[64]; // signature de la transaction avec la clé privée
};

class UTXO // une sortie non dépensée
{
public:
    int nBloc;
    int nTx;
    int nUTX0;         // ces 3 champs nBloc,nTx,nUTX0) forment l'identifiant unique de l'UTXO
    float montant;
    unsigned char dest[KEY_SIZE];  //	compte destinataire (clé publique)
    unsigned char hash[HASH_SIZE];    // hash(nBloc,nTx,nUTXO,montant,destinataire) pour securisation de l'UTXO

    std::string ToString();    // serialisation (necessaire au hash)
};

class TX { // transaction standard (many inputs, many outputs)
public:
    std::vector<TXI>	TXIs;
    std::vector<UTXO>	UTXOs;
};

class TXM { // transaction du mineur : coinbase
public:
    UTXO utxo[1];
};

class Bloc
{
public:
    char hash[HASH_SIZE]; // hash des autres champs, hash of the entire bloc
    unsigned int nonce;

    char previous_hash[HASH_SIZE]; // hash of the previous bloc
    int num; // numero du bloc, commence a zero
    TX tx1; //  transaction du bloc
    TXM tx0; // transaction du mineur (coinbase)

    std::string toString(); // a implementer par le groupe "Fichier"
    std::string toStringSansHash(); // a implementer par le groupe "Fichier"
};

#endif
