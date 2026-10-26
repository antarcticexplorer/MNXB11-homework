#include "MovingObject.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom.h>

void write() {

    MovingObject* obj = new MovingObject();
    TFile* file = new TFile("tree_file.root", "RECREATE");
    TTree* tree = new TTree("tree", "Velocity measurements");

    tree->Branch("object", &obj);

    gRandom->SetSeed(12345);

    const Int_t nMeasurements{10000};
    for (Int_t i{0}; i < nMeasurements; i++) {

        Double_t vx = gRandom->Gaus(0.0, 0.30);
        Double_t vy = gRandom->Gaus(0.0, 0.30);
        Double_t vz = gRandom->Gaus(0.0, 0.30);

        obj->SetVelocity(vx, vy, vz);
        tree->Fill();
    }

    tree->Write();
    file->Close();

    delete obj;
    delete file;
}