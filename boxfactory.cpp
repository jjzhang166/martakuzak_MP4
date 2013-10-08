#include "boxfactory.h"


BoxFactory::BoxFactory(Analyzer *an): analyzer(an)
{}

std::shared_ptr<Box> BoxFactory::getBox(const unsigned int& size, QString type, unsigned long int off, const unsigned int&  e) {
    if(type=="ftyp") {
        QString majorBrand = analyzer->toQString((analyzer->valueOfGroupOfFields(8, 11)),4);
        QString minorVersion = QString::number((analyzer->valueOfGroupOfFields(12, 15)),4);

        QList<QString> compatibleBrands;
        unsigned int index = 16;
        while(index <= (size-4)) {
            QString brand =  analyzer->toQString((analyzer->valueOfGroupOfFields(index, index+3)),4);
            compatibleBrands.append(brand);
            index+=4;
        }

        return std::shared_ptr<Box>(new FileTypeBox(size,type,off,e, majorBrand, minorVersion, compatibleBrands));
    }
    else if(type== "moov"){
        return std::shared_ptr<Box>(new MovieBox(size,type,off,e));
    }
    else if(type=="mdat"){
        return std::shared_ptr<Box>(new MediaDataBox(size,type,off,e));
    }
    else if(type=="mvhd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int version = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        unsigned int creationTime;
        unsigned int modificationTime;
        unsigned int timescale;
        unsigned int duration;
        unsigned int rate;
        unsigned int volume;
        if(version == 1) {
            creationTime = analyzer->valueOfGroupOfFields(offset+12,offset+19);
            modificationTime = analyzer->valueOfGroupOfFields(offset+20, offset+27);
            timescale = analyzer->valueOfGroupOfFields(offset+28, offset+35);
            duration = analyzer->valueOfGroupOfFields(offset+36, offset+43);
        }
        else if(version == 0) {
            creationTime = analyzer->valueOfGroupOfFields(offset+12,offset+15);
            modificationTime = analyzer->valueOfGroupOfFields(offset+16, offset+19);
            timescale = analyzer->valueOfGroupOfFields(offset+20, offset+23);
            duration = analyzer->valueOfGroupOfFields(offset+24, offset+27);
            //unsigned int rate = analyzer->valueOfGroupOfFields(offset+28, offset+31);//fixed number
            //unsigned int volume = analyzer->valueOfGroupOfFields(offset+32, offset+33);
        }

        std::shared_ptr<Box> ret(new MovieHeaderBox(size,type,off,e, version, f, creationTime, modificationTime, timescale, duration,
                                                    rate, volume));
        return ret;
    }
    else if(type=="trak"){
        std::shared_ptr<Box> ret(new TrackBox(size,type,off,e));
        return ret;
    }
    else if(type=="tkhd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new TrackHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="tref"){
        std::shared_ptr<Box> ret(new TrackReferenceBox(size,type,off,e));
        return ret;
    }
    else if(type=="mdia"){
        std::shared_ptr<Box> ret(new MediaBox(size,type,off,e));
        return ret;
    }
    else if(type=="mdhd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new MediaHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="hdlr"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new HandlerBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="minf"){
        std::shared_ptr<Box> ret(new MediaInformationBox(size,type,off,e));
        return ret;
    }
    else if(type=="vmhd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new VideoMediaHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="smhd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SoundMediaHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="hmhd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new HintMediaHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="nmhd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new NullMediaHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="dinf"){
        std::shared_ptr<Box> ret(new DataInformationBox(size,type,off,e));
        return ret;
    }
    else if(type=="url"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new DataEntryUrlBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="urn"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new DataEntryUrnBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="dref"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new DataReferenceBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stbl"){
        std::shared_ptr<Box> ret(new SampleTableBox(size,type,off,e));
        return ret;
    }
    else if(type=="stts"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+9, offset+i+9));
        }
        unsigned int entryCount = analyzer->valueOfGroupOfFields(offset+12, offset+15);

        QList<unsigned int> sampleCount;
        QList<unsigned int> sampleDelta;
        unsigned int index =0;
        unsigned int i = 0;
        while(index<entryCount) {
            sampleCount.append(analyzer->valueOfGroupOfFields(offset+i+16, offset+i+19));
            sampleDelta.append(analyzer->valueOfGroupOfFields(offset+i+20, offset+i+23));
            index++;
            i+=8;
        }
        std::shared_ptr<Box> ret(new TimeToSampleBox(size,type,off,e, v, f, entryCount, sampleCount, sampleDelta));
        return ret;
    }
    else if(type=="ctts"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new CompositionOffsetBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stsd"){
        std::shared_ptr<Box> ret(new SampleDescriptionBox(size,type,off,e));
        return ret;
    }
    else if(type=="stsz"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleSizeBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stz2"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new CompactSampleSizeBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stsc"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleToChunkBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stco"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ChunkOffsetBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="co64"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ChunkLargeOffsetBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stss"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SyncSampleBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stsh"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ShadowSyncSampleBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stdp"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new DegradationPriorityBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="padb"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new PaddingBitsBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="free"){
        std::shared_ptr<Box> ret(new FreeSpaceBox(false,size,type,off,e));
        return ret;
    }
    else if(type=="skip"){
        std::shared_ptr<Box> ret(new FreeSpaceBox(true,size,type,off,e));
        return ret;
    }
    else if(type=="edts"){
        std::shared_ptr<Box> ret(new EditBox(size,type,off,e));
        return ret;
    }
    else if(type=="elst"){
        std::shared_ptr<Box> ret(new EditListBox(size,type,off,e));
        return ret;
    }
    else if(type=="udta"){
        std::shared_ptr<Box> ret(new UserDataBox(size,type,off,e));
        return ret;
    }
    else if(type=="cprt"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new CopyRightBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="mvex"){
        std::shared_ptr<Box> ret(new MovieExtendsBox(size,type,off,e));
        return ret;
    }
    else if(type=="mehd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new MovieExtendsHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="trex"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new TrackExtendsBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="moof"){
        std::shared_ptr<Box> ret(new MovieFragmentBox(size,type,off,e));
        return ret;
    }
    else if(type=="mfhd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        unsigned int sn = analyzer->valueOfGroupOfFields(8,11);
        std::shared_ptr<Box> ret(new MovieFragmentHeaderBox(size,type,off,e, sn, v, f));
        return ret;
    }
    else if(type=="traf"){
        std::shared_ptr<Box> ret(new TrackFragmentBox(size,type,off,e));
        return ret;
    }
    else if(type=="tfhd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new TrackFragmentHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="trun"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new TrackRunBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="mfra"){
        std::shared_ptr<Box> ret(new MovieFragmentRandomAccessBox(size,type,off,e));
        return ret;
    }
    else if(type=="tfra"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new TrackFragmentRandomAccessBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="mfro"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new MovieFragmentRandomAccessOffsetBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="sdtp"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleDependencyTypeBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="sbgp"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleToGroupBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="sgpd"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleGroupDescriptionBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stsl"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleScaleBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="subs"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SubSampleInformationBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="pdin"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ProgressiveDownloadInfoBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="meta"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new MetaBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="xml "){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new XMLBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="bxml"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new BinaryXMLBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="iloc"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ItemLocationBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="pitm"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new PrimaryItemBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="ipro"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ItemProtectionBox(size,type,off,e, v, f));
        return ret;

    }
    else if(type=="infe"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ItemInfoEntry(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="iinf"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ItemInfoBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="sinf"){
        std::shared_ptr<Box> ret(new ProtectionSchemeInfoBox(size,type,off,e));
        return ret;
    }
    else if(type=="frma"){
        std::shared_ptr<Box> ret(new OriginalFormatBox(size,type,off,e));
        return ret;
    }
    else if(type=="imif"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new IPMPInfoBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="ipmc"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new IPMPControlBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="schm"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SchemeTypeBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="schi"){
        std::shared_ptr<Box> ret(new SchemeInformationBox(size,type,off,e));
        return ret;
    }
    else if(type=="tims"){
        std::shared_ptr<Box> ret(new TimeScaleEntry(size,type,off,e));
        return ret;
    }
    else if(type=="tsro"){
        std::shared_ptr<Box> ret(new TimeOffset(size,type,off,e));
        return ret;
    }
    else if(type=="snro"){
        std::shared_ptr<Box> ret(new SequenceOffset(size,type,off,e));
        return ret;
    }
    else if(type=="srpp"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SRTPProcessBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="hnti"){
        std::shared_ptr<Box> ret(new MovieHintInformation(size,type,off,e));
        return ret;
    }
    else if(type=="rtp "){
        std::shared_ptr<Box> ret(new RTPMovieHintInformation(size,type,off,e));
        return ret;
    }
    else if(type=="sdp "){
        std::shared_ptr<Box> ret(new RTPTrackSDPHintInformation(size,type,off,e));
        return ret;
    }
    else if(type=="hinf"){
        std::shared_ptr<Box> ret(new HintStatisticsBox(size,type,off,e));
        return ret;
    }
    //MP4
    else if(type=="iods"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new ObjectDescriptorBox(size,type,off,e, v, f));
    }
    else if(type=="esds"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new ESDBox(size,type,off,e, v, f));
    }
    /*else if(type == "avc1"){
        return std::shared_ptr<Box>(new VisualSampleEntry(size,type,off,e,0,0,0,0,analyzer->valueOfGroupOfFields(32,33),analyzer->valueOfGroupOfFields(34,35)));

    }*/
    else if(type=="mp4v" /*|| type == "avc1"*/){
        return std::shared_ptr<Box>(new MP4VisualSampleEntry(size,type,off,e,0,0,0,0,
                                                             analyzer->valueOfGroupOfFields(32,33),
                                                             analyzer->valueOfGroupOfFields(34,35)));
    }
    else if(type=="mp4a"){
        //33

        return std::shared_ptr<Box>(new MP4AudioSampleEntry(size,type,off,e));
    }
    else if(type=="mp4s"){
        return std::shared_ptr<Box>(new MpegSampleEntry(size,type,off,e));
    }
    else if(type=="saiz"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new SampleAuxiliaryInformationSizesBox(size,type,off,e, v, f));
    }
    else if(type=="saio"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new SampleAuxiliaryInformationOffsetsBox(size,type,off,e, v, f));
    }
    else if(type=="trun"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new TrackRunBox(size,type,off,e, v, f));
    }
    else if(type=="tfdt"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new TrackFragmentBaseMediaDecodeTimeBox(size,type,off,e, v, f));
    }
    else if(type=="leva"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new LevelAssignmentBox(size,type,off,e, v, f));
    }
    else if(type=="sidx"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int version = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        unsigned int referenceId = analyzer->valueOfGroupOfFields(offset + 10, offset + 13);
        unsigned int timescale = analyzer->valueOfGroupOfFields(offset + 14, offset + 17);

        unsigned int earliestPresentationTime = 0;
        unsigned int firstOffset = 0;
        if (version == 0){
            earliestPresentationTime = analyzer->valueOfGroupOfFields(offset + 18, offset + 21);
            firstOffset = analyzer->valueOfGroupOfFields(offset + 22, offset + 25);
            qDebug()<<"first offset 32"<<firstOffset;
        }
        else if (version == 1) {
            earliestPresentationTime = analyzer->valueOfGroupOfFields(offset + 18, offset + 25);
            firstOffset = analyzer->valueOfGroupOfFields(offset + 26, offset + 33);
            qDebug()<<"first offset 64"<<firstOffset;
            offset += 8;
        }
        unsigned int reserved = analyzer->valueOfGroupOfFields(offset + 26,offset + 27);
        unsigned int referenceCount = analyzer->valueOfGroupOfFields(offset + 28, offset + 29);
        QList<bool> referenceType;
        QList<unsigned int> referenceSize;
        QList<unsigned int> subsegmentDuration;
        QList<bool> startsWithSAP;
        QList <unsigned int> SAPType;
        QList <unsigned int> SAPDeltaTime;
        for(unsigned int i = 0; i<referenceCount; i++) {
            referenceType.append(analyzer->bitValue(30,0));
            referenceSize.append(analyzer->valueOfBits(241, 247));
            subsegmentDuration.append(analyzer->valueOfGroupOfFields(31,34));
            startsWithSAP.append(analyzer->bitValue(35,0));
            SAPType.append(analyzer->valueOfBits(281,283));
            SAPDeltaTime.append(analyzer->valueOfBits(284,311));
        }
        return std::shared_ptr<Box>(new SegmentIndexBox(size,type,off,e, version, f, referenceId, timescale, earliestPresentationTime,
                                                        firstOffset, reserved, referenceType, referenceSize, subsegmentDuration,
                                                        startsWithSAP, SAPType, SAPDeltaTime));
    }
    else if(type=="ssix"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int version = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new SubsegmentIndexBox(size,type,off,e, version, f));
    }
    else if(type=="prft"){
        unsigned int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        unsigned int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<unsigned int> f;
        for (unsigned int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new ProducerReferenceTimeBox(size,type,off,e, v, f));
    }
    else{
        return std::shared_ptr<Box>(new Box(size,type,off,e));
        throw NoSuchABoxException();
    }

    return NULL;
}
