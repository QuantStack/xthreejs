#include "xthreejs/audio/xaudio_analyser_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xaudio_analyser>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xaudio_analyser>;
    template xw::xmaterialize<xthree::xaudio_analyser>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xaudio_analyser>>;
    template class xw::xgenerator<xthree::xaudio_analyser>;
    template xw::xgenerator<xthree::xaudio_analyser>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xaudio_analyser>>;
#endif
