#include "boxfactory.h"
#include "exceptions.h"

BoxFactory::BoxFactory(Analyzer *an): analyzer(an)
{}

std::shared_ptr<Box> BoxFactory::getBox(int size,QString type, long int off, int e) {
    if(type=="ftyp") {
        QString majorBrand = analyzer->toQString((analyzer->valueOfGroupOfFields(8, 11)),4);
        QString minorVersion = QString::number((analyzer->valueOfGroupOfFields(12, 15)),4);

        QList<QString> compatibleBrands;
        int index = 16;
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int version = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        int creationTime;
        int modificationTime;
        int timescale;
        int duration;
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
        }
        std::shared_ptr<Box> ret(new MovieHeaderBox(size,type,off,e, version, f, creationTime, modificationTime, timescale, duration));
        return ret;
    }
    else if(type=="trak"){
        std::shared_ptr<Box> ret(new TrackBox(size,type,off,e));
        return ret;
    }
    else if(type=="tkhd"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new MediaHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="hdlr"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new VideoMediaHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="smhd"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SoundMediaHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="hmhd"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new HintMediaHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="nmhd"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new DataEntryUrlBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="urn"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new DataEntryUrnBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="dref"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+9, offset+i+9));
        }
        int entryCount = analyzer->valueOfGroupOfFields(offset+12, offset+15);

        QList<int> sampleCount;
        QList<int> sampleDelta;
        int index =0;
        int i = 0;
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleSizeBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stz2"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new CompactSampleSizeBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stsc"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleToChunkBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stco"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ChunkOffsetBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="co64"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ChunkLargeOffsetBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stss"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SyncSampleBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stsh"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ShadowSyncSampleBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stdp"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new DegradationPriorityBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="padb"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new MovieExtendsHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="trex"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        int sn = analyzer->valueOfGroupOfFields(8,11);
        std::shared_ptr<Box> ret(new MovieFragmentHeaderBox(size,type,off,e, sn, v, f));
        return ret;
    }
    else if(type=="traf"){
        std::shared_ptr<Box> ret(new TrackFragmentBox(size,type,off,e));
        return ret;
    }
    else if(type=="tfhd"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new TrackFragmentHeaderBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="trun"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new TrackFragmentRandomAccessBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="mfro"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new MovieFragmentRandomAccessOffsetBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="sdtp"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleDependencyTypeBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="sbgp"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleToGroupBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="sgpd"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleGroupDescriptionBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="stsl"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SampleScaleBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="subs"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new SubSampleInformationBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="pdin"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ProgressiveDownloadInfoBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="meta"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new MetaBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="xml "){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new XMLBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="bxml"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new BinaryXMLBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="iloc"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ItemLocationBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="pitm"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new PrimaryItemBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="ipro"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ItemProtectionBox(size,type,off,e, v, f));
        return ret;

    }
    else if(type=="infe"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new ItemInfoEntry(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="iinf"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new IPMPInfoBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="ipmc"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        std::shared_ptr<Box> ret(new IPMPControlBox(size,type,off,e, v, f));
        return ret;
    }
    else if(type=="schm"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new ObjectDescriptorBox(size,type,off,e, v, f));
    }
    else if(type=="esds"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new SampleAuxiliaryInformationSizesBox(size,type,off,e, v, f));
    }
    else if(type=="saio"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new SampleAuxiliaryInformationOffsetsBox(size,type,off,e, v, f));
    }
    else if(type=="trun"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new TrackRunBox(size,type,off,e, v, f));
    }
    else if(type=="tfdt"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new TrackFragmentBaseMediaDecodeTimeBox(size,type,off,e, v, f));
    }
    else if(type=="leva"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new LevelAssignmentBox(size,type,off,e, v, f));
    }
    else if(type=="sidx"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new SegmentIndexBox(size,type,off,e, v, f));
    }
    else if(type=="ssix"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
            f.append(analyzer->valueOfGroupOfFields(offset+i+8, offset+i+9));
        }
        return std::shared_ptr<Box>(new SubsegmentIndexBox(size,type,off,e, v, f));
    }
    else if(type=="prft"){
        int offset = 0;
        if(size == 1)
            offset+=8;
        if(type == QString("uuid"))
            offset+=16;
        int v = analyzer->valueOfGroupOfFields(offset+8,offset+8);
        QList<int> f;
        for (int i = 0; i<3; ++i) {
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
