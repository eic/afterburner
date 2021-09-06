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

    hepmc3_out.write_event(evt)
    hepmc3_out.close()


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
    create_zonly_event("zonly_event.hepmc")
    read_events("zonly_event.hepmc")