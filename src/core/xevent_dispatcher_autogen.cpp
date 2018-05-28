#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xevent_dispatcher>;
template xw::xmaterialize<xthree::xevent_dispatcher>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xevent_dispatcher>>;
template class xw::xgenerator<xthree::xevent_dispatcher>;
template xw::xgenerator<xthree::xevent_dispatcher>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xevent_dispatcher>>;