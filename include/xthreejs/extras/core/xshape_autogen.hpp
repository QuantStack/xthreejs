#ifndef XTHREE_SHAPE_HPP
#define XTHREE_SHAPE_HPP

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
    // shape declaration
    //

    template<class D>
    class xshape : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xshape();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using shape = xw::xmaterialize<xshape>;

    using shape_generator = xw::xgenerator<xshape>;

    //
    // shape implementation
    //


    template <class D>
    inline void xshape<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xshape<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xshape<D>::xshape()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xshape<D>::set_defaults()
    {
        this->_model_name() = "ShapeModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xshape>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xshape>;
        extern template xw::xmaterialize<xthree::xshape>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xshape>>;
        extern template class xw::xgenerator<xthree::xshape>;
        extern template xw::xgenerator<xthree::xshape>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xshape>>;
    #endif
#endif

#endif