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
    /**
     * Constructor
     * @param file - TFile to write to
     * @param dir_name - TDirectory name to write histograms to
     */
    Histogrammer(std::shared_ptr<TFile> file, std::string dir_name);

    ~Histogrammer();

    void initialize();

    void process_event(HepMC3::GenEvent& event);

    void finalize();

private:

    std::shared_ptr<TFile> _file;

    TH1D *partPtHist;
    TH1D *partEtaHist;
    TH1D *partPhiHist;

    TH2D *partPtVsEtaHist;
    TH2D *partPhiVsEtaHist;

    TH1D *atan2PxPz1Hist;
    TH1D *atan2PyPz1Hist;
    TH1D *atan2PyPtot1Hist;
    TH1D *atan2PxPz2Hist;
    TH1D *atan2PyPz2Hist;

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
    string _dirname;
};


#endif //EICAFTERBURNER_HISTOGRAMMER_HH
