#include "xthreejs/extras/curves/xcatmull_rom_curve3_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xcatmull_rom_curve3>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xcatmull_rom_curve3>;
    template xw::xmaterialize<xthree::xcatmull_rom_curve3>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xcatmull_rom_curve3>>;
    template class xw::xgenerator<xthree::xcatmull_rom_curve3>;
    template xw::xgenerator<xthree::xcatmull_rom_curve3>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xcatmull_rom_curve3>>;
#endif
