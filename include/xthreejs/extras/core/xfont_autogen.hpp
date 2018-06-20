#ifndef XTHREE_FONT_HPP
#define XTHREE_FONT_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"
#include "../../base/xrender.hpp"

namespace xthree
{
    //
    // font declaration
    //

    template<class D>
    class xfont : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xfont();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using font = xw::xmaterialize<xfont>;

    using font_generator = xw::xgenerator<xfont>;

    //
    // font implementation
    //


    template <class D>
    inline void xfont<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xfont<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xfont<D>::xfont()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xfont<D>::set_defaults()
    {
        this->_model_name() = "FontModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xfont>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xfont>;
        extern template xw::xmaterialize<xthree::xfont>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xfont>>;
        extern template class xw::xgenerator<xthree::xfont>;
        extern template xw::xgenerator<xthree::xfont>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xfont>>;
    #endif
#endif

#endif