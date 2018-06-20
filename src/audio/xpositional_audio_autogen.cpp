#include "xthreejs/audio/xpositional_audio_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xpositional_audio>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xpositional_audio>;
    template xw::xmaterialize<xthree::xpositional_audio>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xpositional_audio>>;
    template class xw::xgenerator<xthree::xpositional_audio>;
    template xw::xgenerator<xthree::xpositional_audio>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xpositional_audio>>;
#endif
