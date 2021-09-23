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
    _file = std::make_unique<TFile>(_output_file_path.c_str(), "RECREATE");
    _file->cd();
    // Particle Quantities
    partPtHist = new TH1D("partPt","Final State Particle Pt",500,0.,50.);
    partEtaHist = new TH1D("partEta","Final State Particle Eta",400,-10.,10.);
    partPhiHist = new TH1D("partPhi","Final State Particle Phi",100,-1.0*TMath::Pi(),TMath::Pi());
    partPtVsEtaHist = new TH2D("partPtVsEta","Final State Particle Pt Vs Eta",400,-10.,10.,500,0.,50.);
    partPhiVsEtaHist = new TH2D("partPhiVsEta","Final State Particle Phi Vs Eta",400,-10.,10.,100,-1.0*TMath::Pi(),TMath::Pi());
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

