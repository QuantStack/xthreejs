#include "xthreejs/helpers/xdirectional_light_helper_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xdirectional_light_helper>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xdirectional_light_helper>;
    template xw::xmaterialize<xthree::xdirectional_light_helper>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xdirectional_light_helper>>;
    template class xw::xgenerator<xthree::xdirectional_light_helper>;
    template xw::xgenerator<xthree::xdirectional_light_helper>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xdirectional_light_helper>>;
#endif
