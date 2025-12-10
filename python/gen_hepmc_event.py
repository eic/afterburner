from pyHepMC3 import HepMC3 as hm


# direction 0.024997395914712332 0 0.9996875162757026

def create_zonly_event(file_name):

    hepmc3_out = hm.WriterAscii(file_name)
    evt = hm.GenEvent(hm.Units.GEV, hm.Units.MM)

    evt.set_event_number(1)

    v1 = hm.GenVertex(hm.FourVector(1, 2, 3, 4))
    evt.add_vertex(v1)

    p1 = hm.GenParticle(hm.FourVector(0, 0, 1000, 1000), 2212, 1)
    evt.add_particle(p1)

    p2 = hm.GenParticle(hm.FourVector(0, 0, 100, 100), 11, 1)
    evt.add_particle(p2)

    v1.add_particle_in(p1)
    v1.add_particle_out(p2)

    hm.Print.listing(evt)
    evt.set_units(hm.Units.GEV,hm.Units.CM)
    hm.Print.listing(evt)

    hepmc3_out.write_event(evt)
    hepmc3_out.close()

def create_simple_event(file_name, n_events=1000, file_type="ascii", electron_energy=18, proton_energy=275):

    writer = None
    if file_type == "ascii":
        writer = hm.WriterAscii(file_name)
    elif file_type == "root":
        writer = hm.WriterRoot(file_name)

    for i in range(n_events):
        evt = hm.GenEvent(hm.Units.GEV, hm.Units.MM)

        evt.set_event_number(i)

        v1 = hm.GenVertex(hm.FourVector(0, 0, 0, 0))

        p1 = hm.GenParticle(hm.FourVector(0, 0, proton_energy, proton_energy), 2212, 4)
        p2 = hm.GenParticle(hm.FourVector(0, 0, -electron_energy, electron_energy), 11, 4)
        
        p3 = hm.GenParticle(hm.FourVector(0, 0, proton_energy, proton_energy), 2212, 1)
        p4 = hm.GenParticle(hm.FourVector(0, 0, -electron_energy, electron_energy), 11, 1)

        v1.add_particle_in(p1)
        v1.add_particle_in(p2)

        v1.add_particle_out(p3)
        v1.add_particle_out(p4)

        evt.add_vertex(v1)
        evt.add_particle(p1)        
        evt.add_particle(p2)
        evt.add_particle(p3)
        evt.add_particle(p4)
        writer.write_event(evt)

    writer.close()


def read_events(file_name):
    input_file = hm.ReaderAscii(file_name)

    if input_file.failed():
        raise "test_create_save_load.failed()"

    while True:
        evt = hm.GenEvent(hm.Units.GEV, hm.Units.CM)
        input_file.read_event(evt)
        if input_file.failed():
            break
        print(f"  evt numbr: {evt.event_number()}")
        print(f"    prt count: {len(evt.particles())}")
        print(f"    vtx count: {len(evt.vertices())}")

        print(dir(hm))
        print(hm.Print.content(evt))
        #    we now print it out in old format
        print(hm.Print.listing(evt, 2))
        #     print each particle so we can see the polarization
        for ip in evt.particles():
            print(hm.Print.line(ip, False))
        evt.clear()

    input_file.close()


if __name__ == "__main__":
    # Generate some simple events to ensure the afterburner can read them
    create_simple_event("beam_18x275_events.hepmc", n_events=10, file_type="ascii", electron_energy=18, proton_energy=275)
    create_zonly_event("zonly_event.hepmc")
    read_events("zonly_event.hepmc")