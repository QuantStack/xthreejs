#include "xthreejs/controls/xorbit_controls_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xorbit_controls>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xorbit_controls>;
    template xw::xmaterialize<xthree::xorbit_controls>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xorbit_controls>>;
    template class xw::xgenerator<xthree::xorbit_controls>;
    template xw::xgenerator<xthree::xorbit_controls>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xorbit_controls>>;
#endif
