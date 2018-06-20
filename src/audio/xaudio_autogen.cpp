#include "xthreejs/audio/xaudio_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xaudio>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xaudio>;
    template xw::xmaterialize<xthree::xaudio>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xaudio>>;
    template class xw::xgenerator<xthree::xaudio>;
    template xw::xgenerator<xthree::xaudio>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xaudio>>;
#endif
