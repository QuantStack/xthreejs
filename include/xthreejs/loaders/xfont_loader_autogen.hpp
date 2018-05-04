#ifndef XTHREE_FONT_LOADER_HPP
#define XTHREE_FONT_LOADER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // font_loader declaration
    //

    template<class D>
    class xfont_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xfont_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using font_loader = xw::xmaterialize<xfont_loader>;

    using font_loader_generator = xw::xgenerator<xfont_loader>;

    //
    // font_loader implementation
    //


    template <class D>
    inline void xfont_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xfont_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xfont_loader<D>::xfont_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xfont_loader<D>::set_defaults()
    {
        this->_model_name() = "FontLoaderModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xfont_loader>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xfont_loader>>;
    extern template class xw::xgenerator<xthree::xfont_loader>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xfont_loader>>;
#endif

#endif