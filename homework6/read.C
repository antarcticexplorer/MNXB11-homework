#include "MovingObject.h"
#include <TFile.h>
#include <TTree.h>
#include <TH2D.h>
#include <TCanvas.h>
#include <iostream>

void read() {
    TFile* file = TFile::Open("tree_file.root", "READ");

    if (!file || file->IsZombie()) {
        std::cerr << "File error" << std::endl;
        return;
    }

    TTree* tree = nullptr;
    file->GetObject("tree", tree);

    if (!tree) {
        std::cerr << "No tree" << std::endl;
        file->Close();
        delete file;
        return;
    }

    MovingObject* obj = nullptr;
    tree->SetBranchAddress("object", &obj);

    TH2D hist("hist",
        "Velocity Components;v_{x} (m/s);v_{y}} (m/s)",
        100, -1.5, 1.5, 100, -1.5, 1.5);

    Long64_t nEntries = tree->GetEntries();

    for (Long64_t i = 0; i < nEntries; i++) {
        tree->GetEntry(i);
        hist.Fill(obj->Vx(), obj->Vy());
    }

    TCanvas c1("c1", "Velocity Components", 800, 600);
    hist.Draw("COLZ");
    c1.SaveAs("velocity_components.png");

    TCanvas c2("c2", "Selected Velocities", 800, 600);

    tree->Draw(
        "sqrt(object.fVx*object.fVx+object.fVy*object.fVy):object.fVz",
        "sqrt(object.fVx*object.fVx+object.fVy*object.fVy+object.fVz*object.fVz)>0.50",
        "P"
    );

    tree->GetHistogram()->SetTitle(
        "Selected Velocities (v > 0.50 m/s);v_{z} (m/s);v_{xy} (m/s)"
    );
    c2.SaveAs("selected_velocities.png");

    tree->ResetBranchAddresses();
    file->Close();
    delete file;
}