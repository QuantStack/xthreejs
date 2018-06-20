#include "xthreejs/audio/xaudio_listener_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xaudio_listener>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xaudio_listener>;
    template xw::xmaterialize<xthree::xaudio_listener>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xaudio_listener>>;
    template class xw::xgenerator<xthree::xaudio_listener>;
    template xw::xgenerator<xthree::xaudio_listener>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xaudio_listener>>;
#endif
