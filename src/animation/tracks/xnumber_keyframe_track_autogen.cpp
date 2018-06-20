#include "xthreejs/animation/tracks/xnumber_keyframe_track_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xnumber_keyframe_track>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xnumber_keyframe_track>;
    template xw::xmaterialize<xthree::xnumber_keyframe_track>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xnumber_keyframe_track>>;
    template class xw::xgenerator<xthree::xnumber_keyframe_track>;
    template xw::xgenerator<xthree::xnumber_keyframe_track>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xnumber_keyframe_track>>;
#endif
