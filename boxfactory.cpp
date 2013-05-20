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
    else if(type=="stsz"){
        ret= new SampleSizeBox(size,type,off,e);
    }
    else if(type=="stz2"){
        ret= new CompactSampleSizeBox(size,type,off,e);
    }
    else if(type=="stsc"){
        ret= new SampleToChunkBox(size,type,off,e);
    }
    else if(type=="stco"){
        ret= new ChunkOffsetBox(size,type,off,e);
    }
    else if(type=="co64"){
        ret= new ChunkLargeOffsetBox(size,type,off,e);
    }
    else if(type=="stbl"){
        ret= new SyncSampleBox(size,type,off,e);
    }
    else if(type=="stdp"){
        ret= new DegradationPriorityBox(size,type,off,e);
    }
    else if(type=="padb"){
        ret= new PaddingBitsBox(size,type,off,e);
    }
    else if(type=="free"){
        ret= new FreeSpaceBox(size,type,off,e);
    }
    else if(type=="skip"){
        ret= new FreeSpaceBox(size,type,off,e);
    }
    else if(type=="edts"){
        ret= new EditBox(size,type,off,e);
    }
    else if(type=="elst"){
        ret= new EditListBox(size,type,off,e);
    }
    else if(type=="udta"){
        ret= new UserDataBox(size,type,off,e);
    }
    else if(type=="cprt"){
        ret= new CopyRightBox(size,type,off,e);
    }
    else if(type=="mvex"){
        ret= new MovieExtendsBox(size,type,off,e);
    }
    else if(type=="mehd"){
        ret= new MovieExtendsHeaderBox(size,type,off,e);
    }
    else if(type=="trex"){
        ret= new TrackExtendsBox(size,type,off,e);
    }
    else if(type=="moof"){
        ret= new MovieFragmentBox(size,type,off,e);
    }
    else if(type=="mfhd"){
        ret= new MovieFragmentHeadreBox(size,type,off,e);
    }
    else if(type=="traf"){
        ret= new TrackFragmentBox(size,type,off,e);
    }
    else if(type=="tfhd"){
        ret= new TrackFragmentHeaderBox(size,type,off,e);
    }
    else if(type=="trun"){
        ret= new TrackRunBox(size,type,off,e);
    }
    else if(type=="mfra"){
        ret= new MovieFragmentRandomAccessBox(size,type,off,e);
    }
    else if(type=="tfra"){
        ret= new TrackFragmentRandomAccessBox(size,type,off,e);
    }
    else if(type=="mfro"){
        ret= new MovieFragmentRandomAccessOffsetBox(size,type,off,e);
    }
    else if(type=="sdtp"){
        ret= new SampleDependencyTypeBox(size,type,off,e);
    }
    else if(type=="sbgp"){
        ret= new SampleToGroupBox(size,type,off,e);
    }
    else if(type=="sgpd"){
        ret= new SampleGroupDescriptionBox(size,type,off,e);
    }
    else if(type=="stsl"){
        ret= new SampleScaleBox(size,type,off,e);
    }
    else if(type=="subs"){
        ret= new SubSampleInformationBox(size,type,off,e);
    }
    else if(type=="pdin"){
        ret= new ProgressiveDownloadInfoBox(size,type,off,e);
    }
    else if(type=="meta"){
        ret= new MetaBox(size,type,off,e);
    }
    else if(type=="xml "){
        ret= new XMLBox(size,type,off,e);
    }
    else if(type=="bxml"){
        ret= new BinaryXMLBox(size,type,off,e);
    }
    else if(type=="iloc"){
        ret= new ItemLocationBox(size,type,off,e);
    }
    else if(type=="pitm"){
        ret= new PrimaryItemBox(size,type,off,e);
    }
    else if(type=="ipro"){
        ret= new ItemProtectionBox(size,type,off,e);
    }
    else if(type=="infe"){
        ret= new ItemInfoEntry(size,type,off,e);
    }
    else if(type=="iinf"){
        ret= new ItemInfoBox(size,type,off,e);
    }
    else if(type=="sinf"){
        ret= new ProtectionSchemeInfoBox(size,type,off,e);
    }
    else if(type=="frma"){
        ret= new OriginalFormatBox(size,type,off,e);
    }
    else if(type=="imif"){
        ret= new IPMPInfoBox(size,type,off,e);
    }
    else if(type=="ipmc"){
        ret= new IPMPControlBox(size,type,off,e);
    }
    else if(type=="schm"){
        ret= new SchemeTypeBox(size,type,off,e);
    }
    else if(type=="schi"){
        ret= new SchemeInformationBox(size,type,off,e);
    }
    else if(type=="tims"){
        ret= new TimeScaleEntry(size,type,off,e);
    }
    else if(type=="tsro"){
        ret= new TimeOffset(size,type,off,e);
    }
    else if(type=="snro"){
        ret= new SequenceOffset(size,type,off,e);
    }
    else if(type=="srpp"){
        ret= new SRTPProcessBox(size,type,off,e);
    }
    else if(type=="hnti"){
        ret= new MovieHintInformation(size,type,off,e);
    }
    else if(type=="rtp "){
        ret= new RTPMovieHintInformation(size,type,off,e);
    }
    else if(type=="sdp "){
        ret= new RTPTrackSDPHintInformation(size,type,off,e);
    }
    else if(type=="hinf"){
        ret= new HintStatisticsBox(size,type,off,e);
    }
    else{
        throw NoSuchABoxException();
    }

    return ret;
}
