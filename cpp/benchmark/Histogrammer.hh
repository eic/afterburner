#ifndef EICAFTERBURNER_HISTOGRAMMER_HH
#define EICAFTERBURNER_HISTOGRAMMER_HH

#include <string>
#include <memory>

#include <HepMC3/GenEvent.h>

class TFile;
class TH1D;
class TH2D;

class Histogrammer {
public:
    Histogrammer(std::string output_file);
    ~Histogrammer();

    void initialize();

    void process_event(HepMC3::GenEvent& event);

    void finalize();

private:
    bool _is_finalized = false;
    std::string _output_file_path;
    std::unique_ptr<TFile> _file;

    TH1D *partPtHist;
    TH1D *partEtaHist;
    TH1D *partPhiHist;

    TH2D *partPtVsEtaHist;
    TH2D *partPhiVsEtaHist;

    TH1D *vtxX;
    TH1D *vtxY;
    TH1D *vtxZ;
    TH1D *vtxT;
    TH1D *vtx2X;
    TH1D *vtx2Y;
    TH1D *vtx2Z;
    TH1D *vtx2T;
    TH2D *vtxYvsX;
    TH2D *vtxXvsT;
    TH2D *vtxXvsZ;
    TH2D *vtxYvsZ;
    TH2D *vtxTvsZ;
    TH2D *vtxXvsTZSum;
    TH2D *vtxXvsTZDiff;
    int _verbose = 0;
};


#endif //EICAFTERBURNER_HISTOGRAMMER_HH
