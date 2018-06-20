#include "xthreejs/core/xevent_dispatcher_autogen.hpp"

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xevent_dispatcher>& widget)
{
    if (not widget.pre)
        widget.pre = std::make_shared<xthree::preview>(xthree::preview(widget));
    return mime_bundle_repr(*widget.pre);
}

#ifdef XTHREEJS_PRECOMPILED
    template class xw::xmaterialize<xthree::xevent_dispatcher>;
    template xw::xmaterialize<xthree::xevent_dispatcher>::xmaterialize();
    template class xw::xtransport<xw::xmaterialize<xthree::xevent_dispatcher>>;
    template class xw::xgenerator<xthree::xevent_dispatcher>;
    template xw::xgenerator<xthree::xevent_dispatcher>::xgenerator();
    template class xw::xtransport<xw::xgenerator<xthree::xevent_dispatcher>>;
#endif
