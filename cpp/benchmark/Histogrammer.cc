#include "Histogrammer.hh"

#include <memory>
#include <utility>

#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TMath.h>

#include <HepMC3/GenParticle.h>

Histogrammer::Histogrammer(std::string output_file):
        _output_file_path(std::move(output_file)),
        _is_finalized(false)
{

}

void Histogrammer::initialize() {
    # creates ROOT file to write things to
    _file = std::make_unique<TFile>(_output_file_path.c_str(), "RECREATE");
    _file->cd();
    // Particle Quantities
    partPtHist = new TH1D("partPt","Final State Particle Pt",500,0.,50.);
    partEtaHist = new TH1D("partEta","Final State Particle Eta",400,-10.,10.);
    partPhiHist = new TH1D("partPhi","Final State Particle Phi",100,-1.0*TMath::Pi(),TMath::Pi());
    partPtVsEtaHist = new TH2D("partPtVsEta","Final State Particle Pt Vs Eta",400,-10.,10.,500,0.,50.);
    partPhiVsEtaHist = new TH2D("partPhiVsEta","Final State Particle Phi Vs Eta",400,-10.,10.,100,-1.0*TMath::Pi(),TMath::Pi());
    /*
    // Beam Shape
  TH1D *eCM = new TH1D("eCM","Modified - Nominal CM Energy",10000,-1.0,1.0);
  TH2D *pXY1 = new TH2D("pXY1","Hadron Beam Py Vs Px",10000,-10.0,10.0,10000,-10.0,10.0);
  TH2D *pXZProd1 = new TH2D("pXZProd1","Hadron Beam Px Vs Vertex z",5000,-500.,500.,10000,-10.0,10.0);
  TH2D *pYZProd1 = new TH2D("pYZProd1","Hadron Beam Py Vs Vertex z",5000,-500.,500.,10000,-10.0,10.0);
  TH2D *pXY2 = new TH2D("pXY2","Lepton Beam Py Vs Px",10000,-10.0,10.0,10000,-10.0,10.0);
  TH2D *pXZProd2 = new TH2D("pXZProd2","Lepton Beam Px Vs Vertex z",5000,-500.,500.,10000,-10.0,10.0);
  TH2D *pYZProd2 = new TH2D("pYZProd2","Lepton Beam Py Vs Vertex z",5000,-500.,500.,10000,-10.0,10.0);
  TH1D *pZ1 = new TH1D("pZ1","Hadron Beam Pz",10000,0.0,280.0);
  TH1D *pZ2 = new TH1D("pZ2","Lepton Beam Pz",10000,-20.,0.);

  TH1D *atan2PxPz1Hist = new TH1D("atan2PxPz1","",2500,0.0,0.05);
  //TH1D *atan2PxPz1Hist = new TH1D("atan2PxPz1","",500,0.24,0.26);
  TH1D *atan2PyPz1Hist = new TH1D("atan2PyPz1","",2500,-0.01,0.01);
  TH1D *atan2PyPtot1Hist = new TH1D("atan2PyPtot1","",500,-0.001,0.001);

  TH1D *vtxX = new TH1D("vtxX","Vertex x;[mm]",5000,-5.0,5.0);
  TH1D *vtxY = new TH1D("vtxY","Vertex y;[mm]",5000,-5.0,5.0);
  TH1D *vtxZ = new TH1D("vtxZ","Vertex z;[mm]",5000,-500.0,500.0);
  TH1D *vtxT = new TH1D("vtxT","Time;[mm]",5000,-500.0,500.0);
  TH2D *vtxYvsX = new TH2D("vtxYvsX","Vertex Y vs X;X [mm];Y [mm]",5000,-5.0,5.0,5000,-5.0,5.0);
  TH2D *vtxXvsT = new TH2D("vtxXvsT","Vertex X vs T;T [mm];X [mm]",5000,-500.0,500.0,5000,-5.0,5.0);
  TH2D *vtxXvsZ = new TH2D("vtxXvsZ","Vertex X vs Z;Z [mm];X [mm]",5000,-500.0,500.0,5000,-5.0,5.0);
  TH2D *vtxYvsZ = new TH2D("vtxYvsZ","Vertex Y vs Z;Z [mm];Y [mm]",5000,-500.0,500.0,5000,-5.0,5.0);
  TH2D *vtxTvsZ = new TH2D("vtxTvsZ","Interaction Time Vs Z-vertex;Z [mm];T [mm]",5000,-500.0,500.0,5000,-500.0,500.0);
  TH2D *vtxXvsTZSum = new TH2D("vtxXvsTZSum","Vertex X vs T+Z;T+Z [mm];X [mm]",5000,-500.,500.,5000,-5.,5.);
  TH2D *vtxXvsTZDiff = new TH2D("vtxXvsTZDiff","Vertex X vs T-Z;T-Z [mm];X [mm]",5000,-500.,500.,5000,-5.,5.);
  
  TH2D *lepVsHadPartZ = new TH2D("lepVsHadPartZ","Intrabunch Z Positions of Colliding Leptons Vs Hadrons",5000,-500.0,500.0,5000,-500.0,500.0);
*/
}


void Histogrammer::process_event(HepMC3::GenEvent &event) {
    for(auto& prt: event.particles()) {
        bool partFin = prt->status() == 1;
        double partPt = prt->momentum().pt();
        double partEta = prt->momentum().eta();
        double partPhi = prt->momentum().phi();

        double px =  prt->momentum().px();
        double py =  prt->momentum().py();
        double pz =  prt->momentum().pz();
        double E =   prt->momentum().e();

        //cout << i << " " << p8.event[i].id() << " " << partPt << " " << partEta << " " << partPhi << endl;

        if(partFin && partEta>-10.0 && partEta<10.0 ) // && y<0.95 && y>0.01 && i > 7)
        {
            partPtHist->Fill(partPt);
            partPhiHist->Fill(partPhi);
            partEtaHist->Fill(partEta);

            partPtVsEtaHist->Fill(partEta,partPt);
            partPhiVsEtaHist->Fill(partEta,partPhi);

//            partStatusVsEtaHist->Fill(partEta,p8.event[i].status());
//
//            if(partPt > 1.0)
//            {
//                partPtHiHist->Fill(partPt);
//                partPhiHiHist->Fill(partPhi);
//                partEtaHiHist->Fill(partEta);
//
//                partPhiVsEtaHiHist->Fill(partEta,partPhi);
//
//                partStatusVsEtaHiHist->Fill(partEta,p8.event[i].status());
//            }
        }
    }
}

void Histogrammer::finalize() {
    _is_finalized = true;

    if(_file) {
        _file->Write();
    }
}

Histogrammer::~Histogrammer() {
    if(!_is_finalized) {
        finalize();
    }
}

