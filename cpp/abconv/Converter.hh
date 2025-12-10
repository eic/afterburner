#ifndef EICAFTERBURNER_CONVERTER_HH
#define EICAFTERBURNER_CONVERTER_HH

#include <memory>

#include <HepMC3/Reader.h>
#include <HepMC3/Writer.h>
#include <afterburner/Afterburner.hh>
#include <functional>
#include <utility>
#include <afterburner/EicConfigurator.hh>


namespace ab{
    namespace abconv{
        class Converter {
        public:

            Converter(std::shared_ptr<HepMC3::Reader> reader,
                      std::shared_ptr<HepMC3::Writer> writer,
                      std::shared_ptr<ab::Afterburner> afterburner);
            void convert();

            void set_verbosity(int verbose) {
                _verbose = verbose;
            }

            void set_last_event_number(uint64_t last_event_number) {
                this->_last_event_number = last_event_number;
            }

            void set_first_event_number(uint64_t first_event_number) {
                this->_first_event_number = first_event_number;
            }

            void set_events_limit(uint64_t events_limit) {
                this->_events_limit = events_limit;
            }

            void set_prior_process_callback(std::function<void(HepMC3::GenEvent&)> after_callback) {
                this->_prior_process_callback = std::move(after_callback);
            }

            void set_after_process_callback(std::function<void(HepMC3::GenEvent&)> after_callback) {
                this->_after_process_callback = std::move(after_callback);
            }

            void set_exit_on_ca(bool b) {
                _exit_on_ca = b;
            }

        private:
            std::shared_ptr<HepMC3::Reader> _reader;
            std::shared_ptr<HepMC3::Writer> _writer;
            std::shared_ptr<ab::Afterburner> _afterburner;
            int _verbose=0;
            uint64_t _first_event_number=0;
            uint64_t _last_event_number=0;
            uint64_t _events_limit=0;
            bool _exit_on_ca=false;

            std::function<void(HepMC3::GenEvent&)> _after_process_callback=nullptr;
            std::function<void(HepMC3::GenEvent&)> _prior_process_callback=nullptr;
            static void print_processed_events(uint64_t count);

            bool check_beams_setup(const HepMC3::GenEvent& event);

            HepMC3::ConstGenParticles get_beam_particles(const HepMC3::GenEvent &event) const;

            void ab_config_to_run_info(const std::shared_ptr<HepMC3::GenRunInfo>& sharedPtr, AfterburnerConfig config);
        };
    }
}


#endif //EICAFTERBURNER_CONVERTER_HH
