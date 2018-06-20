#include "xthreejs/loaders/xloading_manager_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xloading_manager>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xloading_manager>;
    template xw::xmaterialize<xthree::xloading_manager>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xloading_manager>>;
    template class xw::xgenerator<xthree::xloading_manager>;
    template xw::xgenerator<xthree::xloading_manager>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xloading_manager>>;
#endif
