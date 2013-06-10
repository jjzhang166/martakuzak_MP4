#include "boxfactory.h"
#include "exceptions.h"

BoxFactory::BoxFactory(Analyzer *an): analyzer(an)
{}

std::shared_ptr<Box> BoxFactory::getBox(int size,QString type, long int off, int e) {
    if(type=="ftyp") {
        return std::shared_ptr<Box>(new FileTypeBox(size,type,off,e));
    }
    else if(type== "moov"){
        return std::shared_ptr<Box>(new MovieBox(size,type,off,e));
    }
    else if(type=="mdat"){
        return std::shared_ptr<Box>(new MediaDataBox(size,type,off,e));
    }
    else if(type=="mvhd"){
        std::shared_ptr<Box> ret(new MovieHeaderBox(size,type,off,e));
        return ret;
    }
    else if(type=="trak"){
        std::shared_ptr<Box> ret(new TrackBox(size,type,off,e));
        return ret;
    }
    else if(type=="tkhd"){
        std::shared_ptr<Box> ret(new TrackHeaderBox(size,type,off,e));
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
        std::shared_ptr<Box> ret(new MediaHeaderBox(size,type,off,e));
        return ret;
    }
    else if(type=="hdlr"){
        std::shared_ptr<Box> ret(new HandlerBox(size,type,off,e));
        return ret;
    }
    else if(type=="minf"){
        std::shared_ptr<Box> ret(new MediaInformationBox(size,type,off,e));
        return ret;
    }
    else if(type=="vmhd"){
        std::shared_ptr<Box> ret(new VideoMediaHeaderBox(size,type,off,e));
        return ret;
    }
    else if(type=="smhd"){
        std::shared_ptr<Box> ret(new SoundMediaHeaderBox(size,type,off,e));
        return ret;
    }
    else if(type=="hmhd"){
        std::shared_ptr<Box> ret(new HintMediaHeaderBox(size,type,off,e));
        return ret;
    }
    else if(type=="nmhd"){
        std::shared_ptr<Box> ret(new NullMediaHeaderBox(size,type,off,e));
        return ret;
    }
    else if(type=="dinf"){
        std::shared_ptr<Box> ret(new DataInformationBox(size,type,off,e));
        return ret;
    }
    else if(type=="url"){
        std::shared_ptr<Box> ret(new DataEntryUrlBox(size,type,off,e));
        return ret;
    }
    else if(type=="urn"){
        std::shared_ptr<Box> ret(new DataEntryUrnBox(size,type,off,e));
        return ret;
    }
    else if(type=="dref"){
        std::shared_ptr<Box> ret(new DataReferenceBox(size,type,off,e));
        return ret;
    }
    else if(type=="stbl"){
        std::shared_ptr<Box> ret(new SampleTableBox(size,type,off,e));
        return ret;
    }
    else if(type=="stts"){
        std::shared_ptr<Box> ret(new TimeToSampleBox(size,type,off,e));
        return ret;
    }
    else if(type=="ctts"){
        std::shared_ptr<Box> ret(new CompositionOffsetBox(size,type,off,e));
        return ret;
    }
    else if(type=="stsd"){
        std::shared_ptr<Box> ret(new SampleDescriptionBox(size,type,off,e));
        return ret;
    }
    else if(type=="stsz"){
        std::shared_ptr<Box> ret(new SampleSizeBox(size,type,off,e));
        return ret;
    }
    else if(type=="stz2"){
        std::shared_ptr<Box> ret(new CompactSampleSizeBox(size,type,off,e));
        return ret;
    }
    else if(type=="stsc"){
        std::shared_ptr<Box> ret(new SampleToChunkBox(size,type,off,e));
        return ret;
    }
    else if(type=="stco"){
        std::shared_ptr<Box> ret(new ChunkOffsetBox(size,type,off,e));
        return ret;
    }
    else if(type=="co64"){
        std::shared_ptr<Box> ret(new ChunkLargeOffsetBox(size,type,off,e));
        return ret;
    }
    else if(type=="stss"){
        std::shared_ptr<Box> ret(new SyncSampleBox(size,type,off,e));
        return ret;
    }
    else if(type=="stdp"){
        std::shared_ptr<Box> ret(new DegradationPriorityBox(size,type,off,e));
        return ret;
    }
    else if(type=="padb"){
        std::shared_ptr<Box> ret(new PaddingBitsBox(size,type,off,e));
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
        std::shared_ptr<Box> ret(new CopyRightBox(size,type,off,e));
        return ret;
    }
    else if(type=="mvex"){
        std::shared_ptr<Box> ret(new MovieExtendsBox(size,type,off,e));
        return ret;
    }
    else if(type=="mehd"){
        std::shared_ptr<Box> ret(new MovieExtendsHeaderBox(size,type,off,e));
        return ret;
    }
    else if(type=="trex"){
        std::shared_ptr<Box> ret(new TrackExtendsBox(size,type,off,e));
        return ret;
    }
    else if(type=="moof"){
        std::shared_ptr<Box> ret(new MovieFragmentBox(size,type,off,e));
        return ret;
    }
    else if(type=="mfhd"){
        std::shared_ptr<Box> ret(new MovieFragmentHeaderBox(size,type,off,e));
        return ret;
    }
    else if(type=="traf"){
        std::shared_ptr<Box> ret(new TrackFragmentBox(size,type,off,e));
        return ret;
    }
    else if(type=="tfhd"){
        std::shared_ptr<Box> ret(new TrackFragmentHeaderBox(size,type,off,e));
        return ret;
    }
    else if(type=="trun"){
        std::shared_ptr<Box> ret(new TrackRunBox(size,type,off,e));
        return ret;
    }
    else if(type=="mfra"){
        std::shared_ptr<Box> ret(new MovieFragmentRandomAccessBox(size,type,off,e));
        return ret;
    }
    else if(type=="tfra"){
        std::shared_ptr<Box> ret(new TrackFragmentRandomAccessBox(size,type,off,e));
        return ret;
    }
    else if(type=="mfro"){
        std::shared_ptr<Box> ret(new MovieFragmentRandomAccessOffsetBox(size,type,off,e));
        return ret;
    }
    else if(type=="sdtp"){
        std::shared_ptr<Box> ret(new SampleDependencyTypeBox(size,type,off,e));
        return ret;
    }
    else if(type=="sbgp"){
        std::shared_ptr<Box> ret(new SampleToGroupBox(size,type,off,e));
        return ret;
    }
    else if(type=="sgpd"){
        std::shared_ptr<Box> ret(new SampleGroupDescriptionBox(size,type,off,e));
        return ret;
    }
    else if(type=="stsl"){
        std::shared_ptr<Box> ret(new SampleScaleBox(size,type,off,e));
        return ret;
    }
    else if(type=="subs"){
        std::shared_ptr<Box> ret(new SubSampleInformationBox(size,type,off,e));
        return ret;
    }
    else if(type=="pdin"){
        std::shared_ptr<Box> ret(new ProgressiveDownloadInfoBox(size,type,off,e));
        return ret;
    }
    else if(type=="meta"){
        std::shared_ptr<Box> ret(new MetaBox(size,type,off,e));
        return ret;
    }
    else if(type=="xml "){
        std::shared_ptr<Box> ret(new XMLBox(size,type,off,e));
        return ret;
    }
    else if(type=="bxml"){
        std::shared_ptr<Box> ret(new BinaryXMLBox(size,type,off,e));
        return ret;
    }
    else if(type=="iloc"){
        std::shared_ptr<Box> ret(new ItemLocationBox(size,type,off,e));
        return ret;
    }
    else if(type=="pitm"){
        std::shared_ptr<Box> ret(new PrimaryItemBox(size,type,off,e));
        return ret;
    }
    else if(type=="ipro"){
        std::shared_ptr<Box> ret(new ItemProtectionBox(size,type,off,e));
        return ret;

    }
    else if(type=="infe"){
        std::shared_ptr<Box> ret(new ItemInfoEntry(size,type,off,e));
        return ret;
    }
    else if(type=="iinf"){
        std::shared_ptr<Box> ret(new ItemInfoBox(size,type,off,e));
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
        std::shared_ptr<Box> ret(new IPMPInfoBox(size,type,off,e));
        return ret;
    }
    else if(type=="ipmc"){
        std::shared_ptr<Box> ret(new IPMPControlBox(size,type,off,e));
        return ret;
    }
    else if(type=="schm"){
        std::shared_ptr<Box> ret(new SchemeTypeBox(size,type,off,e));
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
        std::shared_ptr<Box> ret(new SRTPProcessBox(size,type,off,e));
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
            return std::shared_ptr<Box>(new ObjectDescriptorBox(size,type,off,e));
        }
    else if(type=="esds"){
            return std::shared_ptr<Box>(new ESDBox(size,type,off,e));
    }
    else if(type=="mp4v"){
        return std::shared_ptr<Box>(new MP4VisualSampleEntry(size,type,off,e));
    }
    else if(type=="mp4a"){
        return std::shared_ptr<Box>(new MP4AudioSampleEntry(size,type,off,e));
    }
    else if(type=="mp4s"){
        return std::shared_ptr<Box>(new MpegSampleEntry(size,type,off,e));
    }
    else{
        return std::shared_ptr<Box>(new Box(size,type,off,e));
        throw NoSuchABoxException();
    }

    return NULL;
}
