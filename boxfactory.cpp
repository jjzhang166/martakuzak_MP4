#include "boxfactory.h"
#include "exceptions.h"

BoxFactory::BoxFactory()
{}

Box* BoxFactory::getBox(int size,QString type, long int off, int e) {
    Box* ret;
    qDebug()<<"BoxFactor::getBox"<<type;
    if(type=="ftyp") {
        ret= new FileTypeBox(size,type,off,e);
    }
    else if(type== "moov"){
        ret= new MovieBox(size,type,off,e);
    }
    else if(type=="mdat"){
        ret= new MediaDataBox(size,type,off,e);
    }
    else if(type=="mvhd"){
        ret= new MovieHeaderBox(size,type,off,e);
    }
    else if(type=="track"){
        ret= new TrackBox(size,type,off,e);
    }
    else if(type=="tkhd"){
        ret= new TrackHeaderBox(size,type,off,e);
    }
    else if(type=="tref"){
        ret= new TrackReferenceBox(size,type,off,e);
    }
    else if(type=="mdia"){
        ret= new MediaBox(size,type,off,e);
    }
    else if(type=="mdhd"){
        ret= new MediaHeaderBox(size,type,off,e);
    }
    else if(type=="hdlr"){
        ret= new HandlerBox(size,type,off,e);
    }
    else if(type=="minf"){
        ret= new MediaInformationBox(size,type,off,e);
    }
    else if(type=="vmhd"){
        ret= new VideoMediaHeaderBox(size,type,off,e);
    }
    else if(type=="smhd"){
        ret= new SoundMediaHeaderBox(size,type,off,e);
    }
    else if(type=="hmhd"){
        ret= new HintMediaHeaderBox(size,type,off,e);
    }
    else if(type=="nmhd"){
        ret= new NullMediaHeaderBox(size,type,off,e);
    }
    else if(type=="dinf"){
        ret= new DataInformationBox(size,type,off,e);
    }
    else if(type=="url"){
        ret= new DataEntryUrlBox(size,type,off,e);
    }
    else if(type=="urn"){
        ret= new DataEntryUrnBox(size,type,off,e);
    }
    else if(type=="dref"){
        ret= new DataReferenceBox(size,type,off,e);
    }
    else if(type=="stbl"){
        ret= new SampleTableBox(size,type,off,e);
    }
    else if(type=="stts"){
        ret= new TimeToSampleBox(size,type,off,e);
    }
    else if(type=="ctts"){
        ret= new CompositionOffsetBox(size,type,off,e);
    }
    else if(type=="stsd"){
        ret= new SampleDescriptionBox(size,type,off,e);
    }
    else{
        throw NoSuchABoxException();
    }

    return ret;
}
